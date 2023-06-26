/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:45:16 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/26 17:03:07 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		else if (check != '\n' && check != '\0')
			is_nl_at_eof = true;
		n_read = read(fd, &check, 1);
	}
	if (is_nl_at_eof)
		count++;
	close(fd);
	return (count);
}

t_point3d	new_point(t_fdf	*s_fdf, char **row, u_int32_t c_i, u_int32_t r_i)
{
	t_point3d	point;

	point.x = (c_i * (WIDTH / (s_fdf->col))) * 0.7;
	point.y = (r_i * (HEIGHT / (s_fdf->col))) * 0.7;
	point.z = ft_atoi(row[c_i]);
	point.col = hex_to_color(row[c_i]);
	return (point);
}

static void	free_tmp(char **row, char *line, ssize_t i)
{
	while (row[++i])
	{
		free (row[i]);
		row[i] = NULL;
	}
	if (row)
	{
		free (row);
		row = NULL;
	}
	if (line)
	{
		free (line);
		line = NULL;
	}
}

void	file_to_2d_arr(t_fdf *s_fdf, int fd)
{
	char		**row;
	char		*line;
	ssize_t		c_i;
	ssize_t		r_i;

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
		free_tmp(row, line, -1);
		line = get_next_line(fd);
		row = ft_split(line, ' ');
	}
	if (line != NULL)
		free_tmp(row, line, -1);
}
