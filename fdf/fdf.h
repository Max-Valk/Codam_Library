/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 15:02:03 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/13 15:19:11 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
// # include <MLX42.h>

# define WIDTH 2000
# define HEIGHT 2000

typedef struct s_point3d
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
}	t_point3d;

typedef	struct s_line
{
	int32_t dx;
	int32_t dy;
	int32_t sx;
	int32_t sy;
	int32_t err;
	int32_t e2;
	u_int32_t x;
	u_int32_t y;
}	t_line;

typedef struct s_rotate
{
	t_point3d	**map;
	t_point3d	p;
	t_point3d	center;
	double		angle;
	double		sin_val;
	double		cos_val;
	u_int32_t	i;
	u_int32_t	j;
	u_int32_t	col;
	u_int32_t	row;
	double	x;
	double	y;
	double	z;
}	t_rotate;

typedef	struct s_fdf
{
	mlx_t		*mlx;
	t_line		*line;
	t_point3d	**map;
	u_int32_t	col;
	u_int32_t	row;
}	t_fdf;


typedef	struct s_input_map
{
	t_point3d	**map;
	u_int32_t	row_count;
	u_int32_t	col_count;
}	t_input_map;

void 		print_input_map(t_fdf *input_map);
u_int32_t	column_count(char **line);
u_int32_t	count_row(char *file);

void		file_to_2d_arr(t_fdf *s_fdf, int fd);
t_point3d	**allocate_struct(u_int32_t rows, u_int32_t collumns);
void	*free_map_struct(u_int32_t end, t_point3d **map);

void		error_exit(char *function, int error_num);
void draw_line(t_point3d start, t_point3d end, t_line *line);
int			fdf(t_fdf *s_fdf);
void	q_rotate(t_rotate *tmp, char axis, t_point3d center);
t_point3d	center_point(t_fdf *rotate);

#endif
