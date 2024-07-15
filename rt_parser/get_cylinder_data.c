/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:08:37 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/15 13:44:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_object	*get_cylinder_data(t_container **data, char **line)
{
	t_object	*obj;
	t_point		points;
	t_vec		vec;
	t_vec		meter;
	t_color		reflect;

	(*line) += 2;
	points = get_3d_coordinates("cylinder", line);
	vec = get_vector("cylinder", line);
	meter.x = get_meter(line);
	meter.y = get_meter(line);
	reflect = get_rgb_color("cylinder", line);
	obj = object_new(CY, NULL, reflect);
	obj->element = init_cylinder(vec, points, meter.x, meter.y);
	object_addback(&(*data)->object, obj);
	return (obj);
}
