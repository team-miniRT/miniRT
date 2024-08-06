/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:56:53 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 12:08:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	point_to_point(t_vec p1, t_vec p2)
{
	double	len;

	len = sqrt((p1.x - p2.x) * (p1.x - p2.x) + \
				(p1.y - p2.y) * (p1.y - p2.y) + \
				(p1.z - p2.z) * (p1.z - p2.z));
	return (len);
}

t_vec	vec_min(t_vec vec1, t_vec vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}

void	print_point(t_vec v)
{
	printf("%f %f %f\n", v.x, v.y, v.z);
}
