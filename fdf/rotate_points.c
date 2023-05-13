/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_points.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 15:08:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/13 15:30:39 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "/Users/mvalk/Desktop/Codam_Library/fdf/MLX42/include/MLX42/MLX42.h"
#include <math.h>

// #include <math.h>
#include <stdint.h>

// typedef struct s_point3d
// {
//     int32_t x;
//     int32_t y;
//     int32_t z;
// } t_point3d;

typedef struct s_quaternion
{
    double w;
    double x;
    double y;
    double z;
} t_quaternion;

t_quaternion create_quaternion(double w, double x, double y, double z)
{
	t_quaternion q = {w, x, y, z};
	return q;
}

t_quaternion quaternion_from_axis_angle(double angle, double x, double y, double z)
{
	double s = sin(angle / 2.0);
	double c = cos(angle / 2.0);
	t_quaternion q = {c, x * s, y * s, z * s};
	return q;
}

t_quaternion quaternion_multiply(t_quaternion q1, t_quaternion q2)
{
	t_quaternion q = {
		q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
		q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
		q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w};
	return (q);
}

t_quaternion quaternion_conjugate(t_quaternion q)
{
	t_quaternion qc = {q.w, -q.x, -q.y, -q.z};
	return qc;
}

t_point3d rotate_point_with_quaternion(t_point3d point, t_quaternion q)
{
	t_quaternion p = {0, point.x, point.y, point.z};
	t_quaternion qc = quaternion_conjugate(q);
	t_quaternion r = quaternion_multiply(q, quaternion_multiply(p, qc));
	t_point3d rotated_point = {round(r.x), round(r.y), round(r.z)};
	return rotated_point;
}

void	q_rotate(t_rotate *tmp, char axis, t_point3d center)
{
	// double	angle;
	t_quaternion 	q;
	// t_point3d	center;

	// center = center_point(tmp);
	for	(u_int32_t i = 0; i < tmp->row; i++)
	{
		for (u_int32_t j = 0; j < tmp->col; j++)
		{
			tmp->p = tmp->map[i][j];
			tmp->p.x -= center.x;
			tmp->p.y -= center.y;
			tmp->p.z -= center.z;
			if (axis == 'x')
				q = quaternion_from_axis_angle(tmp->angle, 1.0, 0, 0);
			if (axis == 'y')
				q = quaternion_from_axis_angle(tmp->angle, 0, 1.0, 0);
			if (axis == 'z')
				q = quaternion_from_axis_angle(tmp->angle, 0, 0, 1.0);
			tmp->p = rotate_point_with_quaternion(tmp->p, q);
			tmp->p.x += center.x;
			tmp->p.y += center.y;
			tmp->p.z += center.z;
			tmp->map[i][j] = tmp->p;
		}
	}
}
