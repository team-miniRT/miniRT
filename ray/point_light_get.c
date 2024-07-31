/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:47:58 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/01 03:46:36 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vec	reflect_light(t_vec	v, t_vec n)
{
	return (vec_minus_vec(v, vec_mult_scal(n, vec_inner_pro(v, n) * 2)));
}

t_vec	get_diffuse(t_light	*light, t_container *scene, t_vec light_dir)
{
	t_color	diffuse;
	double	kd;

	kd = fmax(vec_inner_pro(scene->rec.normal, light_dir), 0.0);
	diffuse = vec_mult_scal(light->light_color, kd);
	return (diffuse);
}

t_vec	get_specular(t_light *light, t_container *scene, \
													t_vec light_dir)
{
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	spec;
	t_color	specular;

	view_dir = vec_unit(vec_mult_scal(scene->ray.dir, -1));
	reflect_dir = reflect_light(vec_mult_scal(light_dir, -1), \
					scene->rec.normal);
	spec = pow(fmax(vec_inner_pro(view_dir, reflect_dir), 0.0), BRIGHTNESS);
	specular = vec_mult_scal(vec_mult_scal(light->light_color, \
											SPEC_LEVEL), spec);
	return (specular);
}

static t_color	light_contribution(t_container *scene, t_light *light, \
									t_vec light_dir)
{
    t_color	diffuse;
    t_color	specular;
    double	brightness;

    light_dir = vec_unit(light_dir);
    diffuse = get_diffuse(light, scene, light_dir);
    specular = get_specular(light, scene, light_dir);
    brightness = light->bright_ratio * LUMEN;
    return (vec_mult_scal(vec_plus_vec(diffuse, specular), brightness));
}

t_color point_light_get(t_container *scene, t_light *light)
{
    t_vec light_dir;
    t_ray light_ray;
    double shadow_intensity;

    light_dir = vec_minus_vec(light->origin, scene->rec.point);
    light_ray = ray_init(vec_plus_vec(scene->rec.point, \
				vec_mult_scal(scene->rec.normal, EPSILON)), light_dir);
    shadow_intensity = in_shadow(scene->object, light_ray, vec_len(light_dir));
    t_color light_contrib = light_contribution(scene, light, light_dir);
    return (vec_mult_scal(light_contrib, 1 - shadow_intensity));
}
