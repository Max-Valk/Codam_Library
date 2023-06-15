/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_moves.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 16:06:45 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/15 16:00:24 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	move_window(t_fdf *s_fdf, char direction, double incr)
{
	if (direction == 'W')
		s_fdf->line->incr_y -= incr;
	if (direction == 'A')
		s_fdf->line->incr_x -= incr;
	if (direction == 'S')
		s_fdf->line->incr_y += incr;
	if (direction == 'D')
		s_fdf->line->incr_x += incr;
}

void	move_scale(t_fdf *s_fdf, char direction, double incr)
{
	static double	scale = 1.0;
	u_int32_t		i;
	u_int32_t		j;

	if (direction == 'R')
		scale = 1.0;
	scale += incr;
	i = 0;
	while (i < s_fdf->row)
	{
		j = 0;
		while (j < s_fdf->col)
		{
			s_fdf->frame->map[i][j].z = s_fdf->frame->map[i][j].z * scale;
			j++;
		}
		i++;
	}
}

void	key_zoom(t_fdf *s_fdf, char dir, double incr)
{
	static double	factor = 1.0;
	u_int32_t		i;
	u_int32_t		j;

	if ((dir == '-' && factor > 0.0) || dir == '+')
		factor += incr;
	if (dir == 'R')
		factor = 1.0;
	i = 0;
	while (i < s_fdf->row)
	{
		j = 0;
		while (j < s_fdf->col)
		{
			s_fdf->frame->map[i][j].x = s_fdf->center.x
				+ ((s_fdf->map[i][j].x - s_fdf->center.x) * factor);
			s_fdf->frame->map[i][j].y = s_fdf->center.y
				+ ((s_fdf->map[i][j].y - s_fdf->center.y) * factor);
			s_fdf->frame->map[i][j].z
				= ((s_fdf->map[i][j].z - s_fdf->center.z) * factor);
			j++;
		}
		i++;
	}
}

void	ft_rotate_hook(t_fdf *s_fdf)
{
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_9))
		gen_f(s_fdf, rotate, 'z', 2);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_7))
		gen_f(s_fdf, rotate, 'z', -2);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_8))
		gen_f(s_fdf, rotate, 'x', 2);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_5))
		gen_f(s_fdf, rotate, 'x', -2);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_4))
		gen_f(s_fdf, rotate, 'y', -2);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_6))
		gen_f(s_fdf, rotate, 'y', 2);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_R))
		gen_f(s_fdf, rotate, 'R', 0);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_ADD))
		gen_f(s_fdf, key_zoom, '+', 0.01);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_KP_SUBTRACT))
		gen_f(s_fdf, key_zoom, '-', -0.01);
}

void	ft_hook(void *param)
{
	t_fdf	*s_fdf;

	s_fdf = (t_fdf *)param;
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(s_fdf->mlx);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_W))
		gen_f(s_fdf, move_window, 'W', HEIGHT / 100);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_A))
		gen_f(s_fdf, move_window, 'A', WIDTH / 100);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_S))
		gen_f(s_fdf, move_window, 'S', HEIGHT / 100);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_D))
		gen_f(s_fdf, move_window, 'D', WIDTH / 100);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_I))
		gen_f(s_fdf, move_scale, 'I', 0.1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_K))
		gen_f(s_fdf, move_scale, 'K', -0.1);
	if (mlx_is_key_down(s_fdf->mlx, MLX_KEY_F))
		gen_f(s_fdf, rotate, 'F', 0);
	ft_rotate_hook(s_fdf);
}
