/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:19:49 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

t_vec	phong_lighting(t_container	*scene)
{
	t_vec		light_color;
	t_object	*lights;
	t_light		*l;

	light_color = make_color(0, 0, 0);
	lights = scene->light;
	l = (t_light *)scene->light->element;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vec_plus_vec(light_color, \
			point_light_get(scene, lights->element));
		lights = lights->next;
	}
	if (vec_len(light_color) != 0)
		light_color = vec_plus_vec(light_color, *scene->ambient);
	return (vec_min(vec_mult_vec(light_color, scene->rec.reflect), \
	make_color(1, 1, 1)));
}
