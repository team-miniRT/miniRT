/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:30:42 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/19 16:41:55 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_object	*get_triangle_data(t_container **data, char **line)
{
	t_object	*obj;
	t_point		vec1;
	t_point		vec2;
	t_point		vec3;
	t_color		reflect;

	(*line) += 3;
	vec1 = get_3d_coordinates("triangle", line);
	vec2 = get_3d_coordinates("triangle", line);
	vec3 = get_3d_coordinates("triangle", line);
	reflect = get_rgb_color("triangle", line);
	obj = object_new(TRI, NULL, reflect);
	obj->element = init_triangle(vec1, vec2, vec3);
	object_addback(&(*data)->object, obj);
	return (obj);
}
