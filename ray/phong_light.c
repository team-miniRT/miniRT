/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:19:49 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 02:49:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// t_color	point_light_get(t_container *scene, t_light *light)
// {
// 	t_color	diffuse;
// 	t_vec	light_dir;
// 	t_color	specular;
// 	t_ray	light_ray;
// 	double	brightness;

// 	light_dir = vec_minus_vec(light->origin, scene->rec.point);
// 	light_ray = ray_init(vec_plus_vec(scene->rec.point, \
// 	vec_mult_scal(scene->rec.normal, EPSILON)), light_dir);
// 	if (in_shadow(scene->object, light_ray, vec_len(light_dir)))
// 		return (make_color(0, 0, 0));
// 	light_dir = vec_unit(vec_minus_vec(light->origin, scene->rec.point));
// 	diffuse = get_diffuse(light, scene, light_dir);
// 	specular = get_specular(light, scene, light_dir);
// 	brightness = light->bright_ratio * LUMEN;
// 	return (vec_mult_scal(vec_plus_vec(diffuse, specular), brightness));
// 	return (vec_mult_scal(specular, brightness));
// }

t_color	phong_lighting(t_container	*scene)
{
	t_color		light_color;
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
