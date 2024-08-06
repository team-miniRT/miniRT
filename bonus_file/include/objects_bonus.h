/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:03:54 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/06 16:08:10 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H

# include "rt_parser_bonus.h"
# include "structor_bonus.h"
# include "vector_bonus.h"
# include "ray_bonus.h"

t_sphere	*init_sphere(t_vec center, double radius);
double		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *ray, t_hit_record *rec);
t_object	*object_new(t_object_type type, void *element, t_vec reflect);
void		object_addback(t_object **list, t_object *new);
t_object	*object_last(t_object *list);
t_plane		*init_plane(t_vec point, t_vec normal);
double		hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
t_cylinder	*init_cylinder(t_vec n, t_vec center, \
							double height, double radius);
double		hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec);
int			discriment_cy(t_ray bot_ray, t_cylinder *cy, \
			double *root1, double *root2);
int			check_in_height(t_hit_record *rec, t_cylinder *cy, \
							t_ray *ray, double t);
int			get_t(t_cylinder *cy, t_ray *ray, t_hit_record *rec, double *t);
double		get_meet_point(t_ray v_ray, t_ray *ray);
int			checker_point(t_vec p, t_sphere *sp);
t_vec		reverse_color(t_vec	color);
t_triangle	*init_triangle(t_vec v, t_vec w, t_vec l);
double		hit_triangle(t_object *obj, t_ray *ray, t_hit_record *rec);
t_vec		calctexture(t_sphere *sp);
void		calculate_texture_coordinates(t_vec p, t_sphere *sp, \
										double *u, double *v);

#endif