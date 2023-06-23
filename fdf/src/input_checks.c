/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:45:16 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/23 15:46:44 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static bool	is_row_filled(char check)
{
	return (check != '\n' && check != '\0');
}

u_int32_t	count_row(int32_t fd)
{
	u_int32_t	count;
	ssize_t		n_read;
	char		check;
	bool		is_nl_at_eof;

	count = 0;
	n_read = read(fd, &check, 1);
	is_nl_at_eof = false;
	while (n_read > 0)
	{
		if (check == '\n')
		{
			if (is_nl_at_eof)
				count++;
			is_nl_at_eof = false;
		}
		else if (is_row_filled(check))
			is_nl_at_eof = true;
		n_read = read(fd, &check, 1);
	}
	close(fd);
	return (count);
}

t_point3d	new_point(t_fdf	*s_fdf, char **row, u_int32_t c_i, u_int32_t r_i)
{
	t_point3d	point;

	point.x = (c_i * (WIDTH / (s_fdf->col))) * 0.6;
	point.y = (r_i * (HEIGHT / (s_fdf->col))) * 0.6;
	point.z = ft_atoi(row[c_i]);
	point.col = hex_to_color(row[c_i]);
	return (point);
}

void	file_to_2d_arr(t_fdf *s_fdf, int fd)
{
	char		**row;
	char		*line;
	u_int32_t	c_i;
	u_int32_t	r_i;

	line = get_next_line(fd);
	row = ft_split(line, ' ');
	s_fdf->col = column_count(row);
	s_fdf->map = allocate_struct(s_fdf->row, s_fdf->col);
	r_i = -1;
	while (++r_i < s_fdf->row)
	{
		c_i = -1;
		if (column_count(row) != s_fdf->col)
			error_exit(EINVAL);
		while (++c_i < s_fdf->col)
			s_fdf->map[r_i][c_i] = new_point(s_fdf, row, c_i, r_i);
		c_i = -1;
		while (row[++c_i])
			free (row[c_i]);
		free (row);
		free (line);
		line = get_next_line(fd);
		row = ft_split(line, ' ');
	}
}
