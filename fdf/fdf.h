/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 15:02:03 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/21 14:53:48 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <MLX42.h>

# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_point3d
{
	int32_t	x;
	int32_t	y;
	double	z;
	int32_t	col;
}	t_point3d;

typedef struct s_quaternion
{
	double		w;
	double		x;
	double		y;
	double		z;
}				t_quaternion;

typedef	struct s_line
{
	int32_t dx;
	int32_t dy;
	int32_t sx;
	int32_t sy;
	int32_t err;
	int32_t e2;
	int32_t x;
	int32_t y;
	int32_t	incr_x;
	int32_t	incr_y;
	int32_t	col;
}	t_line;

typedef struct s_frame
{
	t_point3d	**map;
	t_point3d	center;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	bool		rev_x;
	bool		rev_y;
	u_int32_t	i;
	u_int32_t	j;
	u_int32_t	col;
	u_int32_t	row;
	double	x;
	double	y;
	double	z;
} t_frame;

typedef	struct s_fdf
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	t_line		*line;
	t_frame		*frame;
	t_point3d	**map;
	t_point3d	center;
	u_int32_t	col;
	u_int32_t	row;
}	t_fdf;


// typedef	struct s_input_map
// {
// 	t_point3d	**map;
// 	u_int32_t	row_count;
// 	u_int32_t	col_count;
// }	t_input_map;

int32_t	max_z(t_fdf *s_fdf);
void	set_z(t_fdf *s_fdf);

t_frame	*first_frame(t_fdf *s_fdf);
void		draw_line(t_fdf *s_fdf, t_point3d start, t_point3d end, t_line *line);

u_int32_t	column_count(char **row);
u_int32_t	count_row(char *file);

void		draw_frame(t_fdf *s_fdf, t_frame *frame, t_line *line);
void		file_to_2d_arr(t_fdf *s_fdf, int fd);
t_point3d	**allocate_struct(u_int32_t rows, u_int32_t collumns);
void		*free_map_struct(t_point3d **map);

void		ft_hook(void *param);
void		copy_map(t_fdf *s_fdf, t_frame *frame);
void		error_exit(int err_num);
// void	put_2d_grid(void *param);
void		draw_line(t_fdf *s_fdf, t_point3d start, t_point3d end, t_line *line);
// int			fdf(t_fdf *s_fdf);
void		q_rotate(t_frame *frame, t_point3d center);
t_point3d	center_point(t_fdf *s_fdf);
void		make_quaternions(t_frame *frame, u_int32_t i, u_int32_t j);

void		rotate(t_fdf *s_fdf, char axis, double incr);
void		gen_f(t_fdf *sf, void (*f)(t_fdf *, char, double), char key, double i);
void		move_window(t_fdf *s_fdf, char direction, double incr);
int32_t		init_window(t_fdf *s_fdf);
// void	free_frame(t_fdf *s_fdf);
void		free_struct(t_fdf *s_fdf);
void		copy_map(t_fdf *s_fdf, t_frame *copy);
void		fill_img(t_fdf *s_fdf, int32_t color);
void		key_zoom(t_fdf *s_fdf, char dir, double incr);
void		move_scale(t_fdf *s_fdf, char direction, double incr);
int32_t		hex_to_color(char *hex);
// t_point3d	new_3d_point(int32_t x, int32_t y, int32_t z, int32_t color);
void		calc_z(t_fdf *s_fdf);
t_point3d	new_point(t_fdf	*s_fdf, char **row, u_int32_t c_i, u_int32_t r_i);

#endif
