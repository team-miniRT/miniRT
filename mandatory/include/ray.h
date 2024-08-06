/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:55:51 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/06 00:31:21 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "rt_parser.h"

# define BRIGHTNESS 32
# define SPEC_LEVEL 5
# define SHADOW_RAYS 16
# define AREA_SIZE 0.5

typedef struct s_container	t_container;

t_ray		ray_init(t_vec orig, t_vec dir);
t_vec		ray_at(t_ray *ray, double len);
t_canvas	canvas_init(int width, int height);
t_camera	camera_init(t_canvas *canvas, t_vec orig);
t_ray		ray_primary(t_camera *cam, double x_weight, double y_weight);
t_vec		ray_color(t_container *scene);
t_light		*light_point(t_vec light_origin, t_vec light_color, \
			double bright_ratio);
t_vec		phong_lighting(t_container	*scene);
double		in_shadow(t_object *objs, t_ray light_ray, double light_len);
t_vec		get_color_from_texture(t_img *img, double u, double v);
t_vec		point_light_get(t_container *scene, t_light *light);
#endif