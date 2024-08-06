/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_face_normal_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:43:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	if (vec_inner_pro(ray->dir, rec->normal) < 0)
		rec->front_face = TRUE;
	else
		rec->front_face = FALSE;
	if (rec->front_face == FALSE)
		rec->normal = vec_mult_scal(rec->normal, -1);
}
