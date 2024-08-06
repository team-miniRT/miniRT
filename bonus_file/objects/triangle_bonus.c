/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:40:13 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_bonus.h"

t_triangle	*init_triangle(t_vec v, t_vec w, t_vec l)
{
	t_triangle	*tr;

	tr = ft_calloc(1, sizeof(t_triangle));
	if (tr == NULL)
		rt_error_handler("malloc failed", NULL, 1);
	tr->vertex0 = v;
	tr->vertex1 = w;
	tr->vertex2 = l;
	tr->edge1 = vec_minus_vec(w, v);
	tr->edge2 = vec_minus_vec(l, v);
	tr->normal = vec_unit(vec_outer_pro(tr->edge1, tr->edge2));
	return (tr);
}

static int	rays_outside_the_angle(t_triangle *tr, t_ray *ray, t_vec *q)
{
	t_vec	s;
	double	u;
	double	v;

	s = vec_minus_vec(ray->orig, tr->vertex0);
	u = (1.0 / tr->scale_factor) * vec_inner_pro(s, tr->scale_vector);
	if (u < 0.0 || u > 1.0)
		return (FALSE);
	*q = vec_outer_pro(s, tr->edge1);
	v = (1.0 / tr->scale_factor) * vec_inner_pro(ray->dir, *q);
	if (v < 0.0 || u + v > 1.0)
		return (FALSE);
	return (TRUE);
}

static int	get_scale_factor(t_triangle *tr, t_ray *ray)
{
	if (tr->ray == ray)
		return (TRUE);
	tr->scale_vector = vec_outer_pro(ray->dir, tr->edge2);
	tr->scale_factor = vec_inner_pro(tr->edge1, tr->scale_vector);
	if (tr->scale_factor > -EPSILON && tr->scale_factor < EPSILON)
		return (FALSE);
	return (TRUE);
}

double	hit_triangle(t_object *tr_obj, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*tr;
	t_vec		q;

	tr = tr_obj->element;
	if (!get_scale_factor(tr, ray))
		return (FALSE);
	if (!rays_outside_the_angle(tr, ray, &q))
		return (FALSE);
	rec->t = (1.0 / tr->scale_factor) * vec_inner_pro(tr->edge2, q);
	rec->point = ray_at(ray, rec->t);
	if (rec->t < rec->tmin || rec->t > rec->tmax)
		return (FALSE);
	rec->normal = tr->normal;
	rec->reflect = tr_obj->reflect;
	set_face_normal(ray, rec);
	return (TRUE);
}
