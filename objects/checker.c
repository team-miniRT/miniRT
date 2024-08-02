/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:59 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/02 22:46:52 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int	checker_point(t_vec p, t_sphere *sp)
{
	double	u;
	double	v;
	//double	theta;
	//double	phi;
	t_vec	start;
	t_ray	ray;
	int		hap = 0;


	ray.dir = make_vec(0, 0, 1);
	ray.orig = sp->center;
	start = ray_at(&ray, sp->radius);
	start = vec_minus_vec(start, sp->center);
	p = vec_minus_vec(p, sp->center);
	p = vec_minus_vec(p, start);
	u = eacos(clamp(p.y / sp->radius, -1.0, 1.0)) * 180;
	v = atan2(p.x, p.z) * 180;
	if (u < 0)
	{
		u *= -1;
		u += 20;
	}
	if (v < 0)
	{
		v *= -1;
		v += 20;
	}
	u /= 15;
	v /= 10;
	if ((int)u % 4 > 2)
		hap += 1;
	if ((int)v % 4 > 2)
		hap += 1;
	if (hap != 0)
	{
		if (hap > 1)
			return (TRUE);
		return (FALSE);
	}
	return (TRUE);
}
