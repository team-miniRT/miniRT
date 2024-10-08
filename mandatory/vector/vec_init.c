/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:33:08 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 12:08:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	make_vec(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	make_color(double x, double y, double z)
{
	t_vec	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}

t_vec	make_point(double x, double y, double z)
{
	t_vec	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	set_vector(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}
