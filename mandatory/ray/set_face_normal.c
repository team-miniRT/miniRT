/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_face_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:43:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 11:46:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	if (vec_inner_pro(ray->dir, rec->normal) < 0)
		rec->front_face = TRUE;
	else
		rec->front_face = FALSE;
	if (rec->front_face == FALSE)
		rec->normal = vec_mult_scal(rec->normal, -1);
}
