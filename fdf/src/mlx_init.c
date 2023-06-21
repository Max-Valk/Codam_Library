/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 17:30:22 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/21 16:38:15 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdbool.h>

int32_t	init_window(t_fdf *s_fdf)
{
	static mlx_image_t	*image;
	mlx_t				*mlx;

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

void	calc_print(t_fdf *s_fdf, int32_t x_degr, int32_t y_degr)
{
	if (s_fdf->frame->map[0][0].x > s_fdf->frame->map[0][s_fdf->frame->col - 1].x
		&& ((y_degr < -90 && y_degr > -270) || (y_degr > 0 && y_degr < 90)))
		s_fdf->frame->rev_y = true;
	else
		s_fdf->frame->rev_y = false;
	// if (s_fdf->frame->map[0][0].y > s_fd4f->frame->map[s_fdf->frame->row - 1][0].y)
	// 	s_fdf->frame->rev_y = true;
	// else
	// 	s_fdf->frame->rev_y = false;
}

void	rotate(t_fdf *s_fdf, char axis, double incr)
{
	static int	angles[] = {0, 0, 0};

	if (axis == 'F' || axis == 'R')
	{
		angles[0] = 0;
		angles[1] = 0;
		angles[2] = 0;
	}
	if (axis == 'R')
	{
		angles[0] = 30;
		angles[1] = -30;
	}
	if (axis == 'x')
		angles[0] = (angles[0] + (int32_t)incr) % 360;
	if (axis == 'y')
		angles[1] = (angles[1] + (int32_t)incr) % 360;
	if (axis == 'z')
		angles[2] = (angles[2] + (int32_t)incr) % 360;
	// if ( (angles[0] < 0 && angles[0] > -180))//(angles[0] < 0 && angles[0] > -180) ||
	// 	s_fdf->frame->rev_x = true;
	// else
	// 	s_fdf->frame->rev_x = false;
	// if ( (angles[1] > 0 && angles[1] < 90))//(angles[1] > 0 && angles[1] < 180) ||
	// 	s_fdf->frame->rev_y = true;
	// else
	// 	s_fdf->frame->rev_y = false;
	// if (angles[2] > 90 && angles[2] < 270){
	// 	s_fdf->frame->rev_x = true;
	// 	s_fdf->frame->rev_y = true;
	// }
	// printf("max_z: %i\n", max_z(s_fdf));
	printf("ang_x %i, ang_y %i, ang_z %i\n", angles[0], angles[1], angles[2]);
	s_fdf->frame->angle_x = angles[0] * (M_PI / 180);
	s_fdf->frame->angle_y = angles[1] * (M_PI / 180);
	s_fdf->frame->angle_z = angles[2] * (M_PI / 180);
	q_rotate(s_fdf->frame, s_fdf->center);
	calc_print(s_fdf, angles[0], angles[1]);
	printf("coord topleft x= %i y= %i\n", s_fdf->frame->map[0][0].x, s_fdf->frame->map[0][0].y);
	printf("rev_x %i, rev_y %i\n", s_fdf->frame->rev_x, s_fdf->frame->rev_y);
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
