/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 18:50:51 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/15 16:39:00 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_exit(int err_num)
{
	ft_putendl_fd(strerror(err_num), 2);
	exit(err_num);
}

t_point3d	center_point(t_fdf *s_fdf)
{
	t_point3d	center;

	center.x = s_fdf->map[s_fdf->row - 1][s_fdf->col - 1].x / 2;
	center.y = s_fdf->map[s_fdf->row - 1][s_fdf->col - 1].y / 2;
	center.z = 0;
	return (center);
}

void	fill_img(t_fdf *s_fdf, int32_t color)
{
	u_int32_t	i;
	u_int32_t	j;

	i = 0;
	while (i < s_fdf->image->height)
	{
		j = 0;
		while (j < s_fdf->image->width)
		{
			mlx_put_pixel(s_fdf->image, i, j, color);
			j++;
		}
		i++;
	}
}

void	copy_map(t_fdf *s_fdf, t_frame *copy)
{
	u_int32_t	i;
	u_int32_t	j;

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
}

void	free_struct(t_fdf *s_fdf)
{
	free_map_struct(s_fdf->frame->map);
	free (s_fdf->frame->map);
	free (s_fdf->frame);
	free_map_struct(s_fdf->map);
	free (s_fdf->map);
	free(s_fdf->line);
	free (s_fdf);
}
