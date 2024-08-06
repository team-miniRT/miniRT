/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:54:06 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/05 23:09:56 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_object	*get_plane_data(t_container **data, char **line)
{
	t_object	*obj;
	t_vec		points;
	t_vec		vec;
	t_vec		reflect;

	(*line) += 2;
	points = get_3d_coordinates("plane", line);
	points = vec_minus_vec(points, (*data)->camera->orig);
	vec = get_vector("plane", line);
	reflect = get_rgb_color("plane", line);
	obj = object_new(PL, init_plane(points, vec), reflect);
	object_addback(&(*data)->object, obj);
	return (obj);
}
