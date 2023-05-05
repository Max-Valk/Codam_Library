/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 15:02:03 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/05 14:34:03 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <errno.h>
// # include <MLX42.h>

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_point3d
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
}	t_point3d;

typedef	struct s_input_map
{
	t_point3d	**map;
	u_int32_t	row_count;
	u_int32_t	col_count;
}	t_input_map;

void 		print_input_map(t_input_map *input_map);
u_int32_t	collumn_count(char **line);
u_int32_t	count_row(char *file);

t_input_map	*file_to_2d_arr(u_int32_t row_count, int fd);
t_input_map	*allocate_struct(u_int32_t rows, u_int32_t collumns);
void	*free_map_struct(u_int32_t end, t_point3d **map);

void		error_exit(char *function, int error_num);

#endif
