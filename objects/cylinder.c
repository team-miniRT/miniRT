/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:15:08 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/16 18:11:36 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder	*init_cylinder(t_vec n, t_point center, \
							double height, double radius)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	if (cy == NULL)
		exit(1);
	cy->c_vec = vec_unit(n);
	cy->center = center;
	cy->height = height;
	cy->radius = radius;
	return (cy);
}

double	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;

	cy = cy_obj->element;
	if (is_bottom(cy, ray, rec) == FALSE)
	{
		if (is_side(cy, ray, rec) == FALSE)
			return (FALSE);
	}
	else
		is_side(cy, ray, rec);
	//if (is_side(cy, ray, rec) == FALSE)
	//	return (FALSE);
	rec->reflect = cy_obj->reflect;
	return (TRUE);
}

int	is_bottom(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	if (check_one_bottom(cy, ray, rec, FIRST) == FALSE)
	{
		if (check_one_bottom(cy, ray, rec, SECOND) == FALSE)
			return (FALSE);
	}
	else
		check_one_bottom(cy, ray, rec, SECOND);
	rec->point = ray_at(ray, rec->t);
	set_face_normal(ray, rec);
	return (TRUE);
}

int	check_one_bottom(t_cylinder *cy, t_ray *ray, t_hit_record *rec, int flag)
{
	t_point	r_center;
	t_ray	c_ray;
	double	pl_t;
	t_point	pl_point;
	t_plane	*p;

	c_ray = ray_init(cy->center, vec_mult_scal(cy->c_vec, flag));
	r_center = ray_at(&c_ray, (cy->height / 2));
	if (vec_inner_pro(ray->dir, cy->c_vec) == 0)
		return (FALSE);
	p = init_plane(r_center, vec_mult_scal(cy->c_vec, flag));
	pl_t = -1 * (vec_inner_pro(p->plane_vec, ray->orig) + p->constant) / \
				vec_inner_pro(p->plane_vec, ray->dir);
	free(p);
	pl_point = ray_at(ray, pl_t);
	if (point_to_point(r_center, pl_point) > cy->radius)
	 	return (FALSE);
	if (pl_t < rec->tmin || pl_t > rec->tmax)
		return (FALSE);
	rec->t = pl_t;
	rec->tmax = pl_t;
	rec->normal = vec_mult_scal(cy->c_vec, flag);
	return (TRUE);
}

int	is_side(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	t;

	if (get_t(cy, ray, rec, &t) == FALSE)
		return (FALSE);
	if (check_in_height(rec, cy, ray, t) == FALSE)
		return (FALSE);
	rec->tmax = t;
	rec->t = t;
	rec->point = ray_at(ray, t);
	return (TRUE);
}
