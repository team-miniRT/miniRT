/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:20:36 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/02 10:33:13 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// t_vec	vec_rotate(t_vec vec, t_vec axis, double theta)
// {
// 	t_vec	res;
// 	double	cos_theta;
// 	double	sin_theta;
// 	double	one_minus_cos;

// 	if (axis.y < 0)
// 		axis.y *= -1;
// 	cos_theta = cos(theta);
// 	sin_theta = sin(theta);
// 	one_minus_cos = 1.0 - cos_theta;
// 	res.x = (cos_theta + one_minus_cos * axis.x * axis.x) * vec.x + \
// 			(one_minus_cos * axis.x * axis.y - sin_theta * axis.z) * vec.y + \
// 			(one_minus_cos * axis.x * axis.z + sin_theta * axis.y) * vec.z;
// 	res.y = (one_minus_cos * axis.y * axis.x + sin_theta * axis.z) * vec.x + \
// 			(cos_theta + one_minus_cos * axis.y * axis.y) * vec.y + \
// 			(one_minus_cos * axis.y * axis.z - sin_theta * axis.x) * vec.z;
// 	res.z = (one_minus_cos * axis.z * axis.x - sin_theta * axis.y) * vec.x + \
// 			(one_minus_cos * axis.z * axis.y + sin_theta * axis.x) * vec.y + \
// 			(cos_theta + one_minus_cos * axis.z * axis.z) * vec.z;
// 	return (res);
// }

t_vec	vec_rotate(t_vec vec, t_vec axis, double theta)
{
	t_vec	res;
	double	cos_theta;
	double	sin_theta;
	double	dot;

	cos_theta = cos(theta);
	sin_theta = sin(theta);
	dot = axis.x * vec.x + axis.y * vec.y + axis.z * vec.z;
	res.x = cos_theta * (vec.x - dot * axis.x) + sin_theta * \
			(axis.y * vec.z - axis.z * vec.y) + dot * axis.x;
	res.y = cos_theta * (vec.y - dot * axis.y) + sin_theta * \
			(axis.z * vec.x - axis.x * vec.z) + dot * axis.y;
	res.z = cos_theta * (vec.z - dot * axis.z) + sin_theta * \
			(axis.x * vec.y - axis.y * vec.x) + dot * axis.z;
	return (res);
}