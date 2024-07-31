/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_objects_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:15:25 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 10:13:27 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static void	light_correction(t_vec correction_factor, t_object *obj)
{
	t_light	*light;

	light = (t_light *)obj->element;
	if (light == NULL)
		return ;
	light->origin = vec_minus_vec(light->origin, correction_factor);
}

static void	object_correction(t_vec correction_factor, t_object *obj)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	if (obj->type == SP)
	{
		sp = (t_sphere *)obj->element;
		sp->center = vec_minus_vec(sp->center, correction_factor);
	}
	else if (obj->type == PL)
	{
		pl = (t_plane *)obj->element;
		// pl->constant = -1 * vec_inner_pro(vec_minus_vec(point - correction_factor), )
		// pl->plane_vec = vec_minus_vec(pl->plane_vec,correction_factor);
	}
	else if (obj->type == CY)
	{
		cy = (t_cylinder *)obj->element;
		cy->center = vec_minus_vec(cy->center, correction_factor);
	}
}

void	edit_objects_vector(t_container *data)
{
	t_vec		correction_factor;
	t_object	*obj;

	correction_factor.x = data->camera->orig.x;
	correction_factor.y = data->camera->orig.y;
	correction_factor.z = data->camera->orig.z;
	data->camera->orig = make_vec(0, 0, 0);
	obj = data->light;
	while (obj != NULL)
	{
		light_correction(correction_factor, obj);
		obj = obj->next;
	}
	obj = data->object;
	while (obj != NULL)
	{
		object_correction(correction_factor, obj);
		obj = obj->next;
	}
}
