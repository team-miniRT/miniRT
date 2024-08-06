/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:20:36 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 14:33:17 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static t_vec	apply_matrix_to_vector(t_matrix mat, t_vec vec)
{
	t_vec	result;

	result.x = mat.rix[0][0] * vec.x + \
				mat.rix[0][1] * vec.y + mat.rix[0][2] * vec.z;
	result.y = mat.rix[1][0] * vec.x + \
				mat.rix[1][1] * vec.y + mat.rix[1][2] * vec.z;
	result.z = mat.rix[2][0] * vec.x + \
				mat.rix[2][1] * vec.y + mat.rix[2][2] * vec.z;
	return (result);
}

static t_matrix	create_rotation_matrix(t_vec axis, double angle)
{
	t_matrix	mat;
	double		cos_a;
	double		sin_a;
	double		one_minus_cos;

	cos_a = cos(angle);
	sin_a = sin(angle);
	one_minus_cos = 1.0 - cos_a;
	mat.rix[0][0] = cos_a + axis.x * axis.x * one_minus_cos;
	mat.rix[0][1] = axis.x * axis.y * one_minus_cos - axis.z * sin_a;
	mat.rix[0][2] = axis.x * axis.z * one_minus_cos + axis.y * sin_a;
	mat.rix[1][0] = axis.y * axis.x * one_minus_cos + axis.z * sin_a;
	mat.rix[1][1] = cos_a + axis.y * axis.y * one_minus_cos;
	mat.rix[1][2] = axis.y * axis.z * one_minus_cos - axis.x * sin_a;
	mat.rix[2][0] = axis.z * axis.x * one_minus_cos - axis.y * sin_a;
	mat.rix[2][1] = axis.z * axis.y * one_minus_cos + axis.x * sin_a;
	mat.rix[2][2] = cos_a + axis.z * axis.z * one_minus_cos;
	return (mat);
}

static t_vec	rotate_vector(t_vec vector, t_vec axis, double angle)
{
	t_matrix	mat;

	mat = create_rotation_matrix(axis, angle);
	return (apply_matrix_to_vector(mat, vector));
}

t_vec	get_next_vertex(int idx, t_cone cone, double radius)
{
	t_vec	base_vector;
	t_vec	result;

	if (fabs(cone.unit_vec.x) < fabs(cone.unit_vec.y) && \
		fabs(cone.unit_vec.x) < fabs(cone.unit_vec.z))
		base_vector = (t_vec){1, 0, 0};
	else if (fabs(cone.unit_vec.y) < fabs(cone.unit_vec.x) && \
				fabs(cone.unit_vec.y) < fabs(cone.unit_vec.z))
		base_vector = make_vec(0, 1, 0);
	else
		base_vector = make_vec(0, 0, 1);
	base_vector = vec_outer_pro(cone.unit_vec, base_vector);
	if (vec_len(base_vector) < EPSILON)
	{
		if (base_vector.x == 0 && base_vector.y == 0 && base_vector.z == 0)
			base_vector = make_vec(0, 1, 0);
		else
			base_vector = vec_outer_pro(cone.unit_vec, make_vec(1, 0, 0));
	}
	base_vector = vec_unit(base_vector);
	base_vector = vec_mult_scal(base_vector, radius);
	result = rotate_vector(base_vector, cone.unit_vec, \
							(2 * M_PI / CONE_N) * idx);
	result = vec_plus_vec(cone.base_point, result);
	return (result);
}
