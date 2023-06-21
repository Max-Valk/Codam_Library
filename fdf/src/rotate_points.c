/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_points.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 15:08:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/20 14:12:40 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdint.h>

static t_quaternion	quaternion_axis_agl(double w, double x, double y, double z)
{
	double			s;
	double			c;
	t_quaternion	q;

	s = sin(w / 2.0);
	c = cos(w / 2.0);
	q.w = c;
	q.x = x * s;
	q.y = y * s;
	q.z = z * s;
	return (q);
}

static t_quaternion	quaternion_multiply(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	q;

	q.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	q.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	q.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	q.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (q);
}

static t_quaternion	quaternion_conjugate(t_quaternion q)
{
	t_quaternion	qc;

	qc.w = q.w;
	qc.x = -q.x;
	qc.y = -q.y;
	qc.z = -q.z;
	return (qc);
}

static t_point3d	rotate_point_quaternion(t_point3d point, t_quaternion q)
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

void	make_quaternions(t_frame *frame, u_int32_t i, u_int32_t j)
{
	t_quaternion	qx;
	t_quaternion	qy;
	t_quaternion	qz;

	qz = quaternion_axis_agl(frame->angle_z, 0, 0, 1.0);
	qx = quaternion_axis_agl(frame->angle_x, 1.0, 0, 0);
	qy = quaternion_axis_agl(frame->angle_y, 0, 1.0, 0);
	frame->map[i][j] = rotate_point_quaternion(frame->map[i][j], qz);
	frame->map[i][j] = rotate_point_quaternion(frame->map[i][j], qx);
	frame->map[i][j] = rotate_point_quaternion(frame->map[i][j], qy);
}
