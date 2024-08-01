/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:15:08 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 12:08:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder	*init_cylinder(t_vec n, t_vec center, \
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

static int	check_one_bottom(t_cylinder *cy, t_ray *ray, \
					t_hit_record *rec, int flag)
{
	t_vec	r_center;
	t_ray	c_ray;
	double	pl_t;
	t_vec	pl_point;
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

static int	is_bottom(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	int	hit_top;
	int	hit_bottom;

	hit_top = check_one_bottom(cy, ray, rec, FIRST);
	hit_bottom = check_one_bottom(cy, ray, rec, SECOND);
	if (hit_top == FALSE && hit_bottom == FALSE)
		return (FALSE);
	rec->point = ray_at(ray, rec->t);
	set_face_normal(ray, rec);
	return (TRUE);
}

static int	is_side(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
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

double	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	int			hit_bottom;
	int			hit_side;

	cy = cy_obj->element;
	hit_bottom = is_bottom(cy, ray, rec);
	hit_side = is_side(cy, ray, rec);
	if (!hit_bottom && !hit_side)
		return (FALSE);
	if (hit_bottom && hit_side)
		rec->t = fmin(rec->t, rec->tmax);
	rec->reflect = cy_obj->reflect;
	return (TRUE);
}
