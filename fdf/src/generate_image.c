/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_image.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:40:23 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/15 16:33:11 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_frame(t_fdf *s_fdf, t_frame *frame, t_line *line)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	fill_img(s_fdf, 0 << 24 | 0 << 16 | 0 << 8 | 100);
	while (x < frame->row)
	{
		y = 0;
		while (y < frame->col)
		{
			if (y < frame->col - 1)
				draw_line(s_fdf, frame->map[x][y], frame->map[x][y + 1], line);
			if (x < frame->row - 1)
				draw_line(s_fdf, frame->map[x][y], frame->map[x + 1][y], line);
			y++;
		}
		x++;
	}
}

int32_t	put_line(t_fdf *s_fdf, t_line *l, int32_t color, t_point3d end)
{
	if (l->x + l->incr_x > 0 && l->y + l->incr_y > 0
		&& l->x + l->incr_x < WIDTH && l->y + l->incr_y < HEIGHT)
		mlx_put_pixel(s_fdf->image, l->x + l->incr_x, l->y + l->incr_y, color);
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
	u_int32_t	color;

	if (end.col == 0)
		color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
	else
		color = end.col;
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
		if (put_line(s_fdf, line, color, end))
			break ;
	}
}
