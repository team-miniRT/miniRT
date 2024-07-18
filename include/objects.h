/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:03:54 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/16 19:24:13 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "rt_parser.h"
# include "structor.h"
# include "vector.h"
# include "ray.h"

t_sphere	*init_sphere(t_point center, double radius);
double		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *ray, t_hit_record *rec);
t_object	*object_new(t_object_type type, void *element, t_color reflect);
void		object_addback(t_object **list, t_object *new);
t_object	*object_last(t_object *list);
t_plane		*init_plane(t_point point, t_vec normal);
double		hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
t_cylinder	*init_cylinder(t_vec n, t_point center, \
							double height, double radius);
double		hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec);
int			is_bottom(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int			check_one_bottom(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, int flag);
// double		len_point(t_point p1, t_point p2);
t_ray		get_mid_ray(t_cylinder *cy, t_ray *ray);
int			discriment_cy(t_ray bot_ray, t_cylinder *cy, \
			double *root1, double *root2);
int			is_side(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int			check_in_height(t_hit_record *rec, t_cylinder *cy, t_ray *ray, double t);
int			get_t(t_cylinder *cy, t_ray *ray, t_hit_record *rec, double *t);
double		get_meet_point(t_ray v_ray, t_ray *ray);
int			checker_point(t_point p);

#endif