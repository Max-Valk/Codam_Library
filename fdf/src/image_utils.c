/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 18:53:29 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/21 14:44:12 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int32_t	max_z(t_fdf *s_fdf)
{
	u_int32_t	i;
	u_int32_t	j;
	int32_t		max_z;
	int32_t		tmp_z;

	max_z = 0;
	tmp_z = 0;
	i = 0;
	while (i < s_fdf->row)
	{
		j = 0;
		while (j < s_fdf->col)
		{
			tmp_z = abs(s_fdf->map[i][j].z);
			if (tmp_z > max_z)
				max_z = s_fdf->map[i][j].z;
			j++;
		}
		i++;
	}
	return (max_z);
}

int32_t	put_line(t_fdf *s_fdf, t_line *l, t_point3d end)
{
	if (l->x + l->incr_x > 0 && l->y + l->incr_y > 0
		&& l->x + l->incr_x < WIDTH && l->y + l->incr_y < HEIGHT)
		mlx_put_pixel(s_fdf->image, l->x + l->incr_x, l->y + l->incr_y, l->col);
	if (l->x == end.x && l->y == end.y)
		return (1);
	l->e2 = 2 * l->err;
	if (l->e2 > -l->dy)
	{
		l->err -= l->dy;
		l->x += l->sx;
	}
	if (l->e2 < l->dx)
	{
		l->err += l->dx;
		l->y += l->sy;
	}
	return (0);
}

void	draw_line(t_fdf *s_fdf, t_point3d start, t_point3d end, t_line *line)
{
	line->col = 255 << 24 | 255 << 16 | 255 << 8 | 255;
	if (end.col != 0 && start.col != 0)
		line->col = end.col;
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
		if (put_line(s_fdf, line, end))
			break ;
	}
}
