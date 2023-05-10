/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_mlx_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 13:27:27 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/10 18:17:19 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <MLX42.h>
#include <math.h>

static mlx_image_t *image;

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

void rotate_grid(t_rotate *rotate, double angle, char axis)
{
	rotate->sin_val = sin(angle);
	rotate->cos_val = cos(angle);

	// Calculate the center point of the grid in isometric space
	t_point3d center = {0, 0, 0};
	for (int i = 0; i < rotate->row; i++) {
		for (int j = 0; j < rotate->col; j++) {
			center.x += rotate->map[i][j].x;
			center.y += rotate->map[i][j].y;
			center.z += rotate->map[i][j].z;
		}
	}
	center.x /= (rotate->row * rotate->col);
	center.y /= (rotate->row * rotate->col);
	center.z /= (rotate->row * rotate->col);

	// Rotate each point around the center of the grid
	for (int i = 0; i < rotate->row; i++) {
		for (int j = 0; j < rotate->col; j++) {
			// Subtract the center point
			t_point3d p = rotate->map[i][j];
			p.x -= center.x;
			p.y -= center.y;
			p.z -= center.z;

			// Apply the rotation
			if (axis == 'x') {
				p.y = p.y * rotate->cos_val - p.z * rotate->sin_val;
				p.z = p.y * rotate->sin_val + p.z * rotate->cos_val;
			} else if (axis == 'y') {
				p.x = p.x * rotate->cos_val + p.z * rotate->sin_val;
				p.z = -p.x * rotate->sin_val + p.z * rotate->cos_val;
			} else if (axis == 'z') {
				p.x = p.x * rotate->cos_val - p.y * rotate->sin_val;
				p.y = p.x * rotate->sin_val + p.y * rotate->cos_val;
			}

			// Add the center point back
			p.x += center.x;
			p.y += center.y;
			p.z += center.z;

			rotate->map[i][j] = p;
		}
	}
}

// void	rotate_grid(t_rotate *rotate, double angle, char axis)
// {
// 	rotate->sin_val = sin(angle);
// 	rotate->cos_val = cos(angle);

// 	rotate->i = 0;
// 	while (rotate->i < rotate->row)
// 	{
// 		rotate->j = 0;
// 		while (rotate->j < rotate->col)
// 		{
// 			rotate->x = rotate->map[rotate->i][rotate->j].x;
// 			rotate->y = rotate->map[rotate->i][rotate->j].y;
// 			rotate->z = rotate->map[rotate->i][rotate->j].z;
// 			if (axis == 'x')
// 			{
// 				rotate->map[rotate->i][rotate->j].y =
// 					rotate->y * rotate->cos_val - rotate->z * rotate->sin_val;
// 				rotate->map[rotate->i][rotate->j].z =
// 					rotate->y * rotate->sin_val + rotate->z * rotate->cos_val;
// 			}
// 			if (axis == 'y')
// 			{
// 				rotate->map[rotate->i][rotate->j].x =
// 					rotate->x * rotate->cos_val + rotate->z * rotate->sin_val;
// 				rotate->map[rotate->i][rotate->j].z =
// 					-rotate->x * rotate->sin_val + rotate->z * rotate->cos_val;
// 			}
// 			if (axis == 'z')
// 			{
// 				rotate->map[rotate->i][rotate->j].x =
// 					rotate->x * rotate->cos_val - rotate->y * rotate->sin_val;
// 				rotate->map[rotate->i][rotate->j].y =
// 					rotate->x * rotate->sin_val + rotate->y * rotate->cos_val;
// 			}
// 			rotate->j++;
// 		}
// 		rotate->i++;
// 	}
// }


int32_t	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}



void draw_line(t_point3d start, t_point3d end, t_line *line)
{
	u_int32_t color = ft_pixel(200, 100, 200, 255);
	line->dx = fabs(end.x - start.x);
	line->dy = fabs(end.y - start.y);
	line->sx = start.x < end.x ? 1 : -1;
	line->sy = start.y < end.y ? 1 : -1;
	if (start.x > end.x)
		line->dx = fabs(start.x - end.x);
	if (start.y > end.y)
		line->dy = fabs(start.y - end.y);
	line->err = line->dx - line->dy;
	line->x = start.x;
	line->y = start.y;
	line->z = start.z;

	while (1)
	{
		if (line->x + image->width / 4  > 0 && line->y + image->height / 4 > 0 && line->x + image->width / 4 < WIDTH && line->y + image->height / 4 < HEIGHT)
			mlx_put_pixel(image, line->x + image->width / 4, line->y + image->height / 4, color);
		// if (line->x > 0 && line->y > 0 && line->x < WIDTH && line->y < HEIGHT)
		// 	mlx_put_pixel(image, line->x , line->y , color);
		if (line->x >= end.x - 1 && line->y >= end.y - 1)
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
/*
void	draw_line(t_point3d start, t_point3d end, t_line *line)
{
	u_int32_t	color;
	double		center_x;
	double		center_y;

	color = ft_pixel(200, 100, 200, 255);
	line->dx = fabs(end.x - start.x);
	line->dy = fabs(end.y - start.y);
	line->sx = start.x < end.x ? 1 : -1;
	line->sy = start.y < end.y ? 1 : -1;
	line->err = line->dx - line->dy;
	line->x = start.x;
	line->y = start.y;
	line->z = start.z;

	// Calculate the center of the screen
	center_x = (double)WIDTH / 2;
	center_y = (double)HEIGHT / 2;

	while (1)
	{
		// If the line point is within the screen boundaries, draw it
		if (line->x + center_x > 0 && line->y + center_y > 0
			&& line->x + center_x < WIDTH && line->y + center_y < HEIGHT)
			mlx_put_pixel(image, line->x + center_x, line->y + center_y, color);
		if (line->x >= end.x - 1 && line->y >= end.y - 1)
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
}*/


void	draw_frame(t_fdf *s_fdf, t_line *line)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	// print_input_map(s_fdf);
	fill_img(0 << 24 | 0 << 16 | 0 << 8 | 255);
	while (x < s_fdf->col)
	{
		y = 0;
		while (y < s_fdf->row)
		{
			if (y < s_fdf->row - 1)
				draw_line(s_fdf->map[x][y], s_fdf->map[x][y + 1], line);
			if (x < s_fdf->col - 1)
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
				s_fdf->map[i][j].y -= image->width / 20;
			if (direction == 'A')
				s_fdf->map[i][j].x -= image->width / 20;
			if (direction == 'S')
				s_fdf->map[i][j].y += image->width / 20;
			if (direction == 'D')
				s_fdf->map[i][j].x += image->width / 20;
		}
	}
	// draw_frame(s_fdf, s_fdf->line);
	// fill_img(0 << 24 | 0 << 16 | 0 << 8 | 255);
}

void	ft_hook(void *param)
{
	mlx_t *mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	key_hook(void *param)
{
	t_fdf *fdf = param;

	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		move_window(fdf, 'W');
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		move_window(fdf, 'A');
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		move_window(fdf, 'S');
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		move_window(fdf, 'D');
}

void	put_2d_grid(void *param)
{
	t_fdf		*s_fdf = param;
	// t_line 		*line;
	t_rotate	*rotate;
	u_int32_t	x;
	u_int32_t	y;
	double		angle;
	double		angle2;

	angle = 3 * M_PI / 180;
	angle2 = 45.0 * M_PI / 180;
	s_fdf->line = calloc(1, sizeof(t_line));
	if (!s_fdf->line)
		return ;
	rotate = calloc(1, sizeof(t_rotate));
	if (!rotate)
		return ;
	rotate->map = s_fdf->map;
	rotate->col = s_fdf->col;
	rotate->row = s_fdf->row;

	// fill_img(0 << 24 | 0 << 16 | 0 << 8 | 255);

	rotate_grid(rotate, angle, 'z');
	rotate_grid(rotate, angle, 'y');
	// rotate_grid(rotate, angle, 'x');

	draw_frame(s_fdf, s_fdf->line);
	free (s_fdf->line);
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
	mlx_loop_hook(mlx, put_2d_grid, s_fdf);
	// put_2d_grid(s_fdf);
	image->instances[0].x += 0;
	image->instances[0].y += 0;
	mlx_loop_hook(mlx, ft_hook, mlx);
	// mlx_loop_hook(mlx, key_hook, s_fdf);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
