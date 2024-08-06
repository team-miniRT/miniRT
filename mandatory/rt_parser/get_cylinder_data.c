/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:08:37 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/01 14:38:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_object	*get_cylinder_data(t_container **data, char **line)
{
	t_object	*obj;
	t_vec		points;
	t_vec		vec;
	t_vec		meter;
	t_vec		reflect;

	(*line) += 2;
	points = get_3d_coordinates("cylinder", line);
	points = vec_minus_vec(points, (*data)->camera->orig);
	vec = get_vector("cylinder", line);
	meter.y = get_meter(line) / 2;
	meter.x = get_meter(line);
	reflect = get_rgb_color("cylinder", line);
	obj = object_new(CY, NULL, reflect);
	obj->element = init_cylinder(vec, points, meter.x, meter.y);
	object_addback(&(*data)->object, obj);
	return (obj);
}
