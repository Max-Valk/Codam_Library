/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_mlx_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 13:27:27 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/13 15:49:45 by mvalk         ########   odam.nl         */
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
			// printf("copy: %d, %d, %d\n", copy->map[i][j].x, copy->map[i][j].y, copy->map[i][j].z);
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
		if (line->x + image->width / 4  > 0 && line->y + image->height / 4 > 0 && line->x + image->width / 4 < WIDTH && line->y + image->height / 4 < HEIGHT)
			mlx_put_pixel(image, line->x + image->width / 4, line->y + image->height / 4, color);
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
	u_int32_t	i;
	u_int32_t	j;

	i = 0;
	while (i < s_fdf->row)
	{
		j = 0;
		while (j < s_fdf->col)
		{
			if (direction == 'W')
				s_fdf->map[i][j].y -= image->width / 50;
			if (direction == 'A')
				s_fdf->map[i][j].x -= image->width / 50;
			if (direction == 'S')
				s_fdf->map[i][j].y += image->width / 50;
			if (direction == 'D')
				s_fdf->map[i][j].x += image->width / 50;
			j++;
		}
		i++;
	}
	// draw_frame(s_fdf, s_fdf->line);
	// fill_img(0 << 24 | 0 << 16 | 0 << 8 | 255);
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
				s_fdf->map[i][j].z += image->width / 100;
			if (direction == 'K')
				s_fdf->map[i][j].z -= image->width / 100;
			j++;
		}
		i++;
	}
	// draw_frame(s_fdf, s_fdf->line);
	// fill_img(0 << 24 | 0 << 16 | 0 << 8 | 255);
}

void	ft_hook(void *param)
{
	t_fdf *s_fdf = (t_fdf *)param;
	// mlx_t	*mlx = param;

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
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_I))
		move_scale(s_fdf, 'I');
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_K))
		move_scale(s_fdf, 'K');
}

// void	key_hook(void *param)
// {
// 	t_fdf *fdf = param;

// 	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
// 		move_window(fdf, 'W');
// 	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
// 		move_window(fdf, 'A');
// 	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
// 		move_window(fdf, 'S');
// 	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
// 		move_window(fdf, 'D');
// }

void	put_2d_grid(void *param)
{
	t_fdf		*s_fdf = param;
	static	int	angle2 = 30;
	// t_line 		*line;
	t_rotate	*rotate;
	t_point3d	center;
	u_int32_t	x;
	u_int32_t	y;

	// angle2 = 45.0 * M_PI / 180;
	s_fdf->line = calloc(1, sizeof(t_line));
	if (!s_fdf->line)
		return ;
	rotate = copy_map(s_fdf);
	if (!rotate)
		return ;
	angle2 += 1;
	angle2 = angle2 % 360;
	rotate->angle = angle2 * M_PI / 180;
	// rotate_map(rotate, 'z');
	center = center_point(s_fdf);
	// q_rotate(rotate, 'z', center);
	// q_rotate(rotate, 'x', center);
	q_rotate(rotate, 'y', center);
	// rotate_map(rotate, 'x');
	// rotate_map(rotate, 'y');

	// t_point3d	start = {200, 200, 0};
	// t_point3d	end = {150, 100, 0};
	// draw_line(start, end, s_fdf->line);
	draw_frame(rotate, s_fdf->line);
	free (s_fdf->line);
	free_map_struct(rotate->row, rotate->map);
	free (rotate->map);
	free (rotate);
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
	s_fdf->mlx = mlx;
	mlx_loop_hook(mlx, put_2d_grid, s_fdf);
	// put_2d_grid(s_fdf);
	image->instances[0].x += 0;
	image->instances[0].y += 0;
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop_hook(mlx, ft_hook, s_fdf);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
