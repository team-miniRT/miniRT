/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:03:54 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/04 11:41:35 by jjhang           ###   ########.fr       */
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
//int		in_middle(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int			in_circle(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
int			get_one_point(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, int flag);
double		len_point(t_point p1, t_point p2);
t_ray		get_bottom_ray(t_cylinder *cy, t_ray *ray);
int			discriment_cy(t_ray bot_ray, t_cylinder *cy, t_hit_record *rec, double *root);
int			in_middle(t_cylinder *cy, t_ray *ray, t_hit_record *rec);

#endif