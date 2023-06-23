/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:58:46 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/23 15:12:07 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

u_int32_t	column_count(char **row)
{
	u_int32_t	count;

	if (!row)
		return (0);
	count = 0;
	while (row[count] != NULL && row[count][0] != '\n')
		count++;
	return (count);
}

int32_t	hex_to_color(char *hex_row)
{
	u_int32_t	i;
	int32_t		color;
	u_int32_t	val;
	char		*hex;

	hex = ft_strnstr(hex_row, "0x", ft_strlen(hex_row));
	if (!hex)
		return (0);
	i = 2;
	while (hex[i])
	{
		val = 0;
		if (hex[i] >= '0' && hex[i] <= '9')
			val = hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val = hex[i] - 'F' + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val = hex[i] - 'a' + 10;
		color = (color << 4) | val;
		i++;
	}
	color = (color << 8) | 255;
	return (color);
}

void	*free_map_struct(t_point3d **map)
{
	u_int32_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	return (NULL);
}

t_point3d	**allocate_struct(u_int32_t rows, u_int32_t columns)
{
	t_point3d	**map;
	u_int32_t	i;

	i = -1;
	if (rows < 1 || columns < 1)
		error_exit(EINVAL);
	map = ft_calloc(sizeof(t_point3d *), (rows + 1));
	if (!map)
		error_exit(errno);
	while (++i < rows)
	{
		map[i] = ft_calloc(sizeof(t_point3d), (columns + 1));
		if (!map[i])
			error_exit(errno);
	}
	return (map);
}

void	set_z(t_fdf *s_fdf)
{
	u_int32_t	i;
	u_int32_t	j;
	int32_t		mid;
	double		factor;

	mid = s_fdf->map[s_fdf->row - 1][s_fdf->col - 1].y / 2;
	mid += s_fdf->map[s_fdf->row - 1][s_fdf->col - 1].x / 2;
	mid /= 3;
	factor = mid / max_z(s_fdf);
	i = 0;
	while (i < s_fdf->row)
	{
		j = 0;
		while (j < s_fdf->col)
		{
			s_fdf->map[i][j].z *= factor;
			j++;
		}
		i++;
	}
}
