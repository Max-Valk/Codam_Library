/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_mlx_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 13:27:27 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/09 19:12:46 by mvalk         ########   odam.nl         */
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

void	rotate_grid(t_rotate *rotate, double angle, char axis)
{
	rotate->sin_val = sin(angle);
	rotate->cos_val = cos(angle);

	rotate->i = 0;
	while (rotate->i < rotate->row)
	{
		rotate->j = 0;
		while (rotate->j < rotate->col)
		{
			rotate->x = rotate->map[rotate->i][rotate->j].x;
			rotate->y = rotate->map[rotate->i][rotate->j].y;
			rotate->z = rotate->map[rotate->i][rotate->j].z;
			if (axis == 'x')
			{
				rotate->map[rotate->i][rotate->j].y =
					rotate->y * rotate->cos_val - rotate->z * rotate->sin_val;
				rotate->map[rotate->i][rotate->j].z =
					rotate->y * rotate->sin_val + rotate->z * rotate->cos_val;
			}
			if (axis == 'y')
			{
				rotate->map[rotate->i][rotate->j].x =
					rotate->x * rotate->cos_val + rotate->z * rotate->sin_val;
				rotate->map[rotate->i][rotate->j].z =
					-rotate->x * rotate->sin_val + rotate->z * rotate->cos_val;
			}
			if (axis == 'z')
			{
				rotate->map[rotate->i][rotate->j].x =
					rotate->x * rotate->cos_val - rotate->y * rotate->sin_val;
				rotate->map[rotate->i][rotate->j].y =
					rotate->x * rotate->sin_val + rotate->y * rotate->cos_val;
			}
			rotate->j++;
		}
		rotate->i++;
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
	line->sx = start.x < end.x ? 1 : -1;
	line->sy = start.y < end.y ? 1 : -1;
	line->err = line->dx - line->dy;
	line->x = start.x;
	line->y = start.y;
	line->z = start.z;

	while (1)
	{
		if (line->x + image->width / 2  > 0 && line->y + image->height / 2 > 0 && line->x + image->width / 2 < WIDTH && line->y + image->height / 2 < HEIGHT)
			mlx_put_pixel(image, line->x + image->width / 2, line->y + image->height / 2, color);
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
	// while (1)
	// {
    // if (line->x + image->width / 2.0 > 0 && line->y + image->height / 2.0 > 0 && line->x + image->width / 2.0 < WIDTH && line->y + image->height / 2.0 < HEIGHT)
    //     mlx_put_pixel(image, (int)(line->x + image->width / 2.0), (int)(line->y + image->height / 2.0), color);
    // if (line->x == end.x && line->y == end.y)
    //     break ;
    // line->e2 = 2 * line->err;
    // if (line->e2 > -line->dy)
    // {
    //     line->err -= line->dy;
    //     line->x += line->sx;
    // }
    // if (line->e2 < line->dx)
    // {
    //     line->err += line->dx;
    //     line->y += line->sy;
    // }
	// }
}



void	ft_hook(void *param)
{
	mlx_t *mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	put_2d_grid(void *param)
{
	t_input_map	*input = param;
	t_line *line;
	t_rotate	*rotate;
	u_int32_t x;
	u_int32_t y;
	double angle;
	double angle2;
	angle = -5.0 * M_PI / 180;
	angle2 = 5.0 * M_PI / 180;
	line = calloc(1, sizeof(t_line));
	if (!line)
		return ;
	rotate = calloc(1, sizeof(t_rotate));
	if (!rotate)
		return ;
	rotate->map = input->map;
	rotate->col = input->col_count;
	rotate->row = input->row_count;
	fill_img(0 << 24 | 0 << 16 | 0 << 8 | 255);
	rotate_grid(rotate, angle, 'z');
	rotate_grid(rotate, angle2, 'y');
	rotate_grid(rotate, angle2, 'x');
	x = 0;
	y = 0;
	while (x < input->col_count)
	{
		y = 0;
		while (y < rotate->row)
		{
			// printf("kut\n");
			if (y < rotate->row - 1)
				draw_line(rotate->map[x][y], rotate->map[x][y + 1], line);
			if (x < rotate->col - 1)
				draw_line(rotate->map[x][y], rotate->map[x + 1][y], line);

			y++;
		}
		x++;
	}
	free (line);
	free (rotate);
}

int	fdf(t_input_map *map)
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
	// mlx_loop_hook(mlx, put_2d_grid, map);
	put_2d_grid(map);
	image->instances[0].x += 0;
	image->instances[0].y += 0;
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
