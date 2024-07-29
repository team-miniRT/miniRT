/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 01:04:42 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/29 21:04:03 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_plane	*init_plane(t_point point, t_vec normal)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (pl == NULL)
		exit(1);
	pl->plane_vec = vec_unit(normal);
	pl->constant = -1 * vec_inner_pro(point, normal);
	return (pl);
}

double	hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;

	pl = pl_obj->element;
	if (vec_inner_pro(ray->dir, pl->plane_vec) == 0)
		return (FALSE);
	rec->t = -1 * pl->constant / (vec_inner_pro(ray->dir, pl->plane_vec));
	rec->point = ray_at(ray, rec->t);
	if (rec->t < rec->tmin || rec->t > rec->tmax)
		return (FALSE);
	rec->normal = pl->plane_vec;

	if (pl_obj->skin == e_check)
	{
	 if (checker_point(rec->point))
	 	rec->reflect = make_color(1,1,1);
	 else
	 	rec->reflect = make_color(0,0,0);
	}
	else
  	rec->reflect = pl_obj->reflect;
	set_face_normal(ray, rec);
	return (TRUE);
}
