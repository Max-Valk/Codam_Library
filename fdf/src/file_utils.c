/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:58:46 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/15 16:37:11 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

u_int32_t	column_count(char **line)
{
	u_int32_t	count;

	if (!line)
		return (0);
	count = 0;
	while (line[count] != NULL && line[count][0] != '\n')
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
	map = ft_calloc(sizeof(t_point3d *), (rows + 1));
	if (!map)
		error_exit(errno);
	while (++i < rows)
	{
		map[i] = ft_calloc(sizeof(t_point3d), (columns + 1));
		if (!map[i])
		{
			i = -1;
			while (map[++i])
				free(map[i]);
			free(map);
			error_exit(errno);
		}
	}
	return (map);
}

int32_t	calc_z(int32_t in)
{
	if (in == 0)
		return (0);
	if (in == 1)
		return (1);
	if (in == -1)
		return (-1);
	if (in < 0)
		return (-(10 * log(-in)));
	else
		return (10 * log(in));
}
