/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_image.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:40:23 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/23 13:05:08 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_frame(t_fdf *s_fdf, t_frame *frame, t_line *line)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	fill_img(s_fdf, 0 << 24 | 0 << 16 | 0 << 8 | 150);
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
