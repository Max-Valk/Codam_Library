/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_mlx_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 13:27:27 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/16 20:33:55 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <MLX42.h>
#include <math.h>

static mlx_image_t *image;

t_point3d	center_point(t_fdf *rotate)
{
	u_int32_t	i;
	u_int32_t	j;
	int32_t		max_z = 0;
	int32_t		tmp_z = 0;

	t_point3d	center;
	i = 0;
	center.x = rotate->map[rotate->row - 1][rotate->col - 1].x / 2;
	center.y = rotate->map[rotate->row - 1][rotate->col - 1].y / 2;
	while (i < rotate->row)
	{
		j = 0;
		while (j < rotate->col)
		{
			tmp_z = abs(rotate->map[i][j].z);
			if (tmp_z > max_z)
				max_z = rotate->map[i][j].z;
			j++;
		}
		i++;
	}
	center.z = max_z / 2;
	// printf("center: %d, %d, %d\n", center.x, center.y, center.z);
	return (center);
}

t_rotate	*copy_map(t_fdf *s_fdf)
{
	t_rotate	*copy;
	u_int32_t	i;
	u_int32_t	j;
	
	copy = calloc(sizeof(t_rotate), 1);
	if (!copy)
		return (NULL);
	copy->map = allocate_struct(s_fdf->row, s_fdf->col);
	i = 0;
	while (i < s_fdf->row)
	{
		j = 0;
		while (j < s_fdf->col)
		{
			copy->map[i][j] = s_fdf->map[i][j];
			copy->map[i][j].x = s_fdf->map[i][j].x;
			copy->map[i][j].y = s_fdf->map[i][j].y;
			copy->map[i][j].z = s_fdf->map[i][j].z;
			j++;
		}
		i++;
	}
	copy->col = s_fdf->col;
	copy->row = s_fdf->row;
	copy->p.x = 0;
	copy->p.y = 0;
	copy->p.z = 0;
	return (copy);
}

void	fill_img(int32_t color)
{
	u_int32_t i;
	u_int32_t j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			mlx_put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

int32_t	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}



void draw_line(t_point3d start, t_point3d end, t_line *line)
{
	u_int32_t color = ft_pixel(200, 100, 200, 255);
	line->dx = abs(end.x - start.x);
	line->dy = abs(end.y - start.y);
	if (start.x < end.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (start.y < end.y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
	line->x = start.x;
	line->y = start.y;
	while (1)
	{
		if (line->x + line->incr_x  > 0 && line->y + line->incr_y > 0 && line->x + line->incr_x < WIDTH && line->y + line->incr_y < HEIGHT)
			mlx_put_pixel(image, line->x + line->incr_x, line->y + line->incr_y, color);
		// if (line->x > 0 && line->y > 0 && line->x < WIDTH && line->y < HEIGHT)
		// 	mlx_put_pixel(image, line->x , line->y , color);
		if (line->x == end.x && line->y == end.y)
			break ;
		line->e2 = 2 * line->err;
		if (line->e2 > -line->dy)
		{
			line->err -= line->dy;
			line->x += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			line->y += line->sy;
		}
	}
}

void	draw_frame(t_rotate *s_fdf, t_line *line)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	// print_input_map(s_fdf);
	fill_img(0 << 24 | 0 << 16 | 0 << 8 | 100);
	while (x < s_fdf->row)
	{
		y = 0;
		while (y < s_fdf->col)
		{
			if (y < s_fdf->col - 1)
				draw_line(s_fdf->map[x][y], s_fdf->map[x][y + 1], line);
			if (x < s_fdf->row - 1)
				draw_line(s_fdf->map[x][y], s_fdf->map[x + 1][y], line);
			y++;
		}
		x++;
	}
}

void	move_window(t_fdf *s_fdf, char direction)
{
	if (direction == 'W')
		s_fdf->line->incr_y -= image->height / 100;
	if (direction == 'A')
		s_fdf->line->incr_x -= image->width / 100;
	if (direction == 'S')
		s_fdf->line->incr_y += image->height / 100;
	if (direction == 'D')
		s_fdf->line->incr_x += image->width / 100;
}

void	move_scale(t_fdf *s_fdf, char direction)
{
	u_int32_t	i;
	u_int32_t	j;

	i = 0;
	while (i < s_fdf->row)
	{
		j = 0;
		while (j < s_fdf->col)
		{
			if (direction == 'I')
				s_fdf->map[i][j].z += s_fdf->map[i][j].z / 10 + 1;
			if (direction == 'K')
				s_fdf->map[i][j].z -= s_fdf->map[i][j].z / 10 + 1;
			j++;
		}
		i++;
	}
	put_2d_grid(s_fdf);
}

void	key_rotate(t_fdf *s_fdf, char axis, int32_t incr)
{
	t_point3d	center;
	t_frame		*frame;

	center = center_point(s_fdf);
	frame = rotate_grid(s_fdf, center, axis, incr);
	if (!frame)
		return ;
	draw_frame(frame, s_fdf->line);

	free_map_struct(frame->row, frame->map);
	free (frame->map);
	free (frame);
}

void	ft_hook(void *param)
{
	t_fdf *s_fdf = (t_fdf *)param;

	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(s_fdf->mlx);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_W))
		move_window(s_fdf, 'W');
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_A))
		move_window(s_fdf, 'A');
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_S))
		move_window(s_fdf, 'S');
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_D))
		move_window(s_fdf, 'D');
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_PAGE_UP))
		move_scale(s_fdf, 'I');
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_PAGE_DOWN))
		move_scale(s_fdf, 'K');
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_9))
		key_rotate(s_fdf, 'z', 1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_7))
		key_rotate(s_fdf, 'z', -1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_8))
		key_rotate(s_fdf, 'x', 1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_5))
		key_rotate(s_fdf, 'x', -1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_4))
		key_rotate(s_fdf, 'y', -1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_6))
		key_rotate(s_fdf, 'y', 1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_R))
		key_rotate(s_fdf, 'R', 30);
	
}

t_frame	*rotate_grid(t_fdf *s_fdf, t_point3d center, char axis, int32_t incr)
{
	static	int	angles[] = {0, 0, 0};
	t_frame	*frame;

	frame = copy_map(s_fdf);
	if (!frame)
		return (NULL);
	if (axis == 'R')
	{
		angles[0] = 35;
		angles[1] = 0;
		angles[2] = 45;
	}
	if (axis == 'x')
		angles[0] = (angles[0] + incr) % 360;
	if (axis == 'y')
		angles[1] = (angles[1] + incr) % 360;
	if (axis == 'z')
		angles[2] = (angles[2] + incr) % 360;
	frame->angle_x = angles[0] * M_PI / 180;
	frame->angle_y = angles[1] * M_PI / 180;
	frame->angle_z = angles[2] * M_PI / 180;
	q_rotate(frame, 'x', center);
	q_rotate(frame, 'y', center);
	q_rotate(frame, 'z', center);
	return (frame);
}

void	put_2d_grid(void *param)
{
	t_fdf		*s_fdf = param;
	t_frame	*frame;
	t_point3d	center;

	center = center_point(s_fdf);
	frame = rotate_grid(s_fdf, center, 'R', 45);
	// frame = rotate_grid(s_fdf, center, 'z', 45);
	if (!frame)
		return ;
	draw_frame(frame, s_fdf->line);

	free_map_struct(frame->row, frame->map);
	free (frame->map);
	free (frame);
}

int	fdf(t_fdf *s_fdf)
{
	mlx_t	*mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "fdf", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	s_fdf->line->incr_x = image->width / 4;
	s_fdf->line->incr_y = image->height / 4;
	s_fdf->mlx = mlx;
	put_2d_grid(s_fdf);
	// image->instances[0].x += 0;
	// image->instances[0].y += 0;
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop_hook(mlx, ft_hook, s_fdf);
	// mlx_loop_hook(mlx, put_2d_grid, s_fdf);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
