/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_image.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:40:23 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/21 15:38:37 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_frame_rev_x(t_fdf *s_fdf, t_frame *frame, t_line *line)
{
	int32_t	x;
	int32_t	y;

	x = frame->row - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < frame->col)
		{
			if (y < frame->col - 1)
				draw_line(s_fdf, frame->map[x][y], frame->map[x][y + 1], line);
			if (x > 0)
				draw_line(s_fdf, frame->map[x][y], frame->map[x - 1][y], line);
			y++;
		}
		x--;
	}
}

void	draw_frame_rev(t_fdf *s_fdf, t_frame *frame, t_line *line)
{
	int32_t	x;
	int32_t	y;

	x = frame->row - 1;
	while (x >= 0)
	{
		y = frame->col - 1;
		while (y >= 0)
		{
			if (x > 0)
				draw_line(s_fdf, frame->map[x][y], frame->map[x - 1][y], line);
			if (y > 0)
				draw_line(s_fdf, frame->map[x][y], frame->map[x][y - 1], line);
			y--;
		}
		x--;
	}
}

void	draw_frame_rev_y(t_fdf *s_fdf, t_frame *frame, t_line *line)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	while (x < frame->row)
	{
		y = frame->col - 1;
		while (y >= 0)
		{
			if (x < frame->row - 1)
				draw_line(s_fdf, frame->map[x][y], frame->map[x + 1][y], line);
			if (y > 0)
				draw_line(s_fdf, frame->map[x][y], frame->map[x][y - 1], line);
			y--;
		}
		x++;
	}
}

void	draw_frame(t_fdf *s_fdf, t_frame *frame, t_line *line)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	fill_img(s_fdf, 0 << 24 | 0 << 16 | 0 << 8 | 150);
	if (frame->rev_x == true && frame->rev_y == true)
		return (draw_frame_rev(s_fdf, frame, line));
	else if (frame->rev_x == true)
		return (draw_frame_rev_x(s_fdf, frame, line));
	else if (frame->rev_y == true)
		return (draw_frame_rev_y(s_fdf, frame, line));
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
