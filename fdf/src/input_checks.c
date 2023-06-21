/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:45:16 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/21 14:57:18 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

u_int32_t	count_row(char *file)
{
	u_int32_t	count;
	ssize_t		n_read;
	char		check;
	int			fd;

	count = 0;
	n_read = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(errno);
	while (n_read > 0)
	{
		n_read = read(fd, &check, 1);
		if (n_read == -1)
		{
			close(fd);
			error_exit(errno);
		}
		if (check == '\n')
			count++;
	}
	close(fd);
	return (count - 1);
}

t_point3d	new_point(t_fdf	*s_fdf, char **row, u_int32_t c_i, u_int32_t r_i)
{
	t_point3d	point;

	point.x = (c_i * (WIDTH / (s_fdf->col))) * 0.8;
	point.y = (r_i * (HEIGHT / (s_fdf->col))) * 0.8;
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
		while (c_i-- > 0)
			free (row[c_i]);
		free (row);
		free (line);
		line = get_next_line(fd);
		row = ft_split(line, ' ');
	}
	set_z(s_fdf);
}
