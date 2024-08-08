/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:40:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/08 13:44:32 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

double	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;
	t_ray			random_ray;
	int				s_cnt;
	int				idx;

	s_cnt = 0;
	idx = 0;
	while (idx < SHADOW_RAYS)
	{
		random_ray.orig = vec_plus_vec(light_ray.orig, \
							vec_mult_scal(random_in_unit_vec(), AREA_SIZE));
		random_ray.dir = light_ray.dir;
		rec.tmin = 0;
		rec.tmax = light_len;
		if (hit(objs, &random_ray, &rec))
			s_cnt++;
		idx++;
	}
	return ((double)s_cnt / SHADOW_RAYS * 0.7);
}
