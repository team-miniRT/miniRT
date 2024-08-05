/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:59 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/05 19:04:28 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vec	reverse_color(t_vec	color)
{
	t_vec	ret;

	ret.x = 1 - color.x;
	ret.y = 1 - color.y;
	ret.z = 1 - color.z;
	return (ret);
}

int	checker_point(t_vec p, t_sphere *sp)
{
	double	u;
	double	v;
	t_vec	start;
	t_ray	ray;
	int		sum;

	sum = 0;
	ray.dir = make_vec(0, 0, 1);
	ray.orig = sp->center;
	start = ray_at(&ray, sp->radius);
	start = vec_minus_vec(start, sp->center);
	p = vec_minus_vec(p, sp->center);
	u = acos(p.y / sp->radius) * 2000 / M_PI;
	v = atan2f(p.x, p.z) * 2000 / M_PI;
	sum = ((abs((int)u) / 100) + (abs((int)v) / 100)) % 2;
	if (u * v >= 0)
	{
		if (sum == 1)
			return (TRUE);
		return (FALSE);
	}
	if (sum == 1)
		return (FALSE);
	return (TRUE);
}
