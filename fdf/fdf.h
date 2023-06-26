/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 15:02:03 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/26 15:45:52 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <MLX42.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_axis
{
	int32_t		x;
	int32_t		y;
	int32_t		z;
}			t_axis;

typedef struct s_point3d
{
	int32_t		x;
	int32_t		y;
	double		z;
	int32_t		col;
}				t_point3d;

typedef struct s_quaternion
{
	double		w;
	double		x;
	double		y;
	double		z;
}				t_quaternion;

typedef struct s_line
{
	int32_t		dx;
	int32_t		dy;
	int32_t		sx;
	int32_t		sy;
	int32_t		err;
	int32_t		e2;
	int32_t		x;
	int32_t		y;
	int32_t		incr_x;
	int32_t		incr_y;
	int32_t		col;
}				t_line;

typedef struct s_frame
{
	t_point3d	**map;
	t_point3d	center;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	u_int32_t	i;
	u_int32_t	j;
	u_int32_t	col;
	u_int32_t	row;
}				t_frame;

typedef struct s_fdf
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	t_line		*line;
	t_frame		*frame;
	t_point3d	**map;
	t_point3d	center;
	u_int32_t	col;
	u_int32_t	row;
}				t_fdf;

/*								input handling								  */

t_point3d	**allocate_struct(u_int32_t rows, u_int32_t collumns);
void		file_to_2d_arr(t_fdf *s_fdf, int fd);
u_int32_t	column_count(char **row);
u_int32_t	count_row(int32_t fd);
t_point3d	new_point(t_fdf *s_fdf, char **row, u_int32_t c_i, u_int32_t r_i);
double		max_z(t_fdf *s_fdf);
void		set_z(t_fdf *s_fdf);
int32_t		hex_to_color(char *hex);

/*								initializing image							  */

int32_t		init_fdf(t_fdf *s_fdf);
t_frame		*first_frame(t_fdf *s_fdf);
void		copy_map(t_fdf *s_fdf, t_frame *frame);

/*								drawing image								  */

void		fill_img(t_fdf *s_fdf, int32_t color);
void		draw_frame(t_fdf *s_fdf, t_frame *frame, t_line *line);
void		draw_line(t_fdf *s_fdf, t_point3d start, t_point3d end,
				t_line *line);

/*								rotations									  */

t_point3d	center_point(t_fdf *s_fdf);
void		rotate(t_fdf *s_fdf, char axis, double incr);
void		q_rotate(t_frame *frame, t_point3d center);
void		make_quaternions(t_frame *frame, u_int32_t i, u_int32_t j);

/*								free and error handling						  */

void		error_exit(int err_num);
void		free_struct(t_fdf *s_fdf);
void		*free_map_struct(t_point3d **map);

/*								transformations								  */

void		ft_hook(void *param);
void		move_window(t_fdf *s_fdf, char direction, double incr);
void		key_zoom(t_fdf *s_fdf, char dir, double incr);
void		move_scale(t_fdf *s_fdf, char direction, double incr);
void		gen_f(t_fdf *sf, void (*f)(t_fdf *, char, double), char key,
				double i);

#endif
