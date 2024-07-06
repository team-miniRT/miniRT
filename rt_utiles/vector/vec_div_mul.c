/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_div_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:55:15 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/01 16:15:52 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_mult_vec(t_vec vec1, t_vec vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1);
}

t_vec	vec_mult_scal(t_vec vec, double k)
{
	//if (vec.x != 0.0)
		vec.x *= k;
	//if (vec.y != 0.0)
		vec.y *= k;
	//if (vec.z != 0.0)
		vec.z *= k;
	return (vec);
}

t_vec	vec_div(t_vec vec, double t)
{
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
