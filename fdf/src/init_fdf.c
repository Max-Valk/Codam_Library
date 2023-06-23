/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_fdf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 17:30:22 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/23 14:49:50 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdbool.h>

int32_t	init_fdf(t_fdf *s_fdf)
{
	static mlx_image_t	*image;
	mlx_t				*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		return (ft_putendl_fd(mlx_strerror(mlx_errno), 2), 1);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		return (mlx_close_window(mlx),
			ft_putendl_fd(mlx_strerror(mlx_errno), 2), 1);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		return (mlx_close_window(mlx),
			ft_putendl_fd(mlx_strerror(mlx_errno), 2), 1);
	s_fdf->mlx = mlx;
	s_fdf->image = image;
	s_fdf->frame = first_frame(s_fdf);
	rotate(s_fdf, 'R', 0);
	draw_frame(s_fdf, s_fdf->frame, s_fdf->line);
	mlx_loop_hook(mlx, ft_hook, s_fdf);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	q_rotate(t_frame *frame, t_point3d center)
{
	u_int32_t			i;
	u_int32_t			j;

	i = 0;
	while (i < frame->row)
	{
		j = 0;
		while (j < frame->col)
		{
			frame->map[i][j].x -= center.x;
			frame->map[i][j].y -= center.y;
			frame->map[i][j].z -= center.z;
			make_quaternions(frame, i, j);
			frame->map[i][j].x += center.x;
			frame->map[i][j].y += center.y;
			frame->map[i][j].z += center.z;
			j++;
		}
		i++;
	}
}

void	rotate(t_fdf *s_fdf, char axis, double incr)
{
	static t_axis	angles = {0, 0, 0};

	if (axis == 'F' || axis == 'R')
	{
		angles.x = 0;
		angles.y = 0;
		angles.z = 0;
	}
	if (axis == 'R')
	{
		angles.x = 30;
		angles.z = 45;
	}
	if (axis == 'x')
		angles.x = (angles.x + (int32_t)incr) % 360;
	if (axis == 'y')
		angles.y = (angles.y + (int32_t)incr) % 360;
	if (axis == 'z')
		angles.z = (angles.z + (int32_t)incr) % 360;
	s_fdf->frame->angle_x = angles.x * (M_PI / 180);
	s_fdf->frame->angle_y = angles.y * (M_PI / 180);
	s_fdf->frame->angle_z = angles.z * (M_PI / 180);
	q_rotate(s_fdf->frame, s_fdf->center);
}

t_frame	*first_frame(t_fdf *s_fdf)
{
	t_frame	*frame;

	frame = ft_calloc(1, sizeof(t_frame));
	if (!frame)
		error_exit(errno);
	s_fdf->line->incr_y = (HEIGHT - s_fdf->map[s_fdf->row - 1][0].y) / 2;
	s_fdf->line->incr_x = (WIDTH - s_fdf->map[0][s_fdf->col - 1].x) / 2;
	frame->map = allocate_struct(s_fdf->row, s_fdf->col);
	copy_map(s_fdf, frame);
	s_fdf->center = center_point(s_fdf);
	return (frame);
}

void	gen_f(t_fdf *sf, void (*f)(t_fdf *, char, double), char key, double i)
{
	sf->center = center_point(sf);
	if (key == 'R' || key == 'F')
	{
		key_zoom(sf, key, 0);
		move_scale(sf, key, 0);
		rotate(sf, key, 0);
		sf->line->incr_y = (HEIGHT - sf->map[sf->row - 1][0].y) / 2;
		sf->line->incr_x = (WIDTH - sf->map[0][sf->col - 1].x) / 2;
		draw_frame(sf, sf->frame, sf->line);
		return ;
	}
	f(sf, key, i);
	key_zoom(sf, '0', 0);
	move_scale(sf, '0', 0);
	rotate(sf, '0', 0);
	draw_frame(sf, sf->frame, sf->line);
}
