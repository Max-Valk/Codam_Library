/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_points.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 15:08:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/15 16:32:58 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
// #include "/Users/mvalk/Desktop/Codam_Library/fdf/MLX42/include/MLX42/MLX42.h"
// #include <math.h>

// #include <math.h>
#include <stdint.h>

// typedef struct s_point3d
// {
//     int32_t x;
//     int32_t y;
//     int32_t z;
// } t_point3d;

// typedef struct s_quaternion
// {
// 	double		w;
// 	double		x;
// 	double		y;
// 	double		z;
// }				t_quaternion;

t_quaternion	create_quaternion(double w, double x, double y, double z)
{
	t_quaternion	q;

	q.w = w;
	q.x = x;
	q.y = y;
	q.z = z;
	return (q);
}

t_quaternion	quaternion_axis_agl(double agl, double x, double y, double z)
{
	double			s;
	double			c;
	t_quaternion	q;

	s = sin(agl / 2.0);
	c = cos(agl / 2.0);
	q.w = c;
	q.x = x * s;
	q.y = y * s;
	q.z = z * s;
	return (q);
}

t_quaternion	quaternion_multiply(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	q;

	q.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	q.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	q.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	q.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (q);
}

t_quaternion	quaternion_conjugate(t_quaternion q)
{
	t_quaternion	qc;

	qc.w = q.w;
	qc.x = -q.x;
	qc.y = -q.y;
	qc.z = -q.z;
	return (qc);
}

t_point3d	rotate_point_with_quaternion(t_point3d point, t_quaternion q)
{
	t_quaternion	p;
	t_quaternion	qc;
	t_quaternion	r;
	t_point3d		rotated_point;

	p.w = 0;
	p.x = point.x;
	p.y = point.y;
	p.z = point.z;
	qc = quaternion_conjugate(q);
	r = quaternion_multiply(q, quaternion_multiply(p, qc));
	rotated_point.x = round(r.x);
	rotated_point.y = round(r.y);
	rotated_point.z = round(r.z);
	rotated_point.col = point.col;
	return (rotated_point);
}

void	q_rotate(t_frame *frame, char axis, t_point3d center)
{
	t_quaternion		q;
	u_int32_t			i;
	u_int32_t			j;

	i = 0;
	j = 0;
	while (i < frame->row)
	{
		j = 0;
		while (j < frame->col)
		{
			frame->map[i][j].x -= center.x;
			frame->map[i][j].y -= center.y;
			frame->map[i][j].z -= center.z;
			if (axis == 'x')
				q = quaternion_axis_agl(frame->angle_x, 1.0, 0, 0);
			if (axis == 'y')
				q = quaternion_axis_agl(frame->angle_y, 0, 1.0, 0);
			if (axis == 'z')
				q = quaternion_axis_agl(frame->angle_z, 0, 0, 1.0);
			frame->map[i][j] = rotate_point_with_quaternion(frame->map[i][j], q);
			frame->map[i][j].x += center.x;
			frame->map[i][j].y += center.y;
			frame->map[i][j].z += center.z;
			j++;
		}
		i++;
	}
}
