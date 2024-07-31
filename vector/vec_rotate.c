/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:20:36 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 11:13:10 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_rotate(t_vec vec, t_vec axis, double theta)
{
	t_vec	res;
	double	cos_theta;
	double	sin_theta;
	double	one_minus_cos;

	if (axis.y < 0)
		axis.y *= -1;
	cos_theta = cos(theta);
	sin_theta = sin(theta);
	one_minus_cos = 1.0 - cos_theta;
	res.x = (cos_theta + one_minus_cos * axis.x * axis.x) * vec.x + \
			(one_minus_cos * axis.x * axis.y - sin_theta * axis.z) * vec.y + \
			(one_minus_cos * axis.x * axis.z + sin_theta * axis.y) * vec.z;
	res.y = (one_minus_cos * axis.y * axis.x + sin_theta * axis.z) * vec.x + \
			(cos_theta + one_minus_cos * axis.y * axis.y) * vec.y + \
			(one_minus_cos * axis.y * axis.z - sin_theta * axis.x) * vec.z;
	res.z = (one_minus_cos * axis.z * axis.x - sin_theta * axis.y) * vec.x + \
			(one_minus_cos * axis.z * axis.y + sin_theta * axis.x) * vec.y + \
			(cos_theta + one_minus_cos * axis.z * axis.z) * vec.z;
	return (res);
}
