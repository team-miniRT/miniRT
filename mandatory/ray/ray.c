/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:43:10 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 12:08:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray_init(t_vec orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_unit(dir);
	return (ray);
}

t_vec	ray_at(t_ray *ray, double len)
{
	t_vec	dest;

	dest = vec_plus_vec(ray->orig, vec_mult_scal(vec_unit(ray->dir), len));
	return (dest);
}

t_ray	ray_primary(t_camera *cam, double x_weight, double y_weight)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vec_unit((vec_minus_vec(vec_plus_vec(\
	vec_plus_vec(cam->left_bottom, vec_mult_scal(cam->horizontal, x_weight)), \
	vec_mult_scal(cam->vertical, y_weight)), cam->orig)));
	return (ray);
}

t_vec	ray_color(t_container *scene)
{
	scene->rec = record_init();
	if (hit(scene->object, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	return (make_color(0, 0, 0));
}
