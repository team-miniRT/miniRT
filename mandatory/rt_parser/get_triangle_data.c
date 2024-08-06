/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:30:42 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/01 12:08:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_object	*get_triangle_data(t_container **data, char **line)
{
	t_object	*obj;
	t_vec		vec1;
	t_vec		vec2;
	t_vec		vec3;
	t_vec		reflect;

	(*line) += 3;
	vec1 = get_3d_coordinates("triangle", line);
	vec1 = vec_minus_vec(vec1, (*data)->camera->orig);
	vec2 = get_3d_coordinates("triangle", line);
	vec2 = vec_minus_vec(vec2, (*data)->camera->orig);
	vec3 = get_3d_coordinates("triangle", line);
	vec3 = vec_minus_vec(vec3, (*data)->camera->orig);
	reflect = get_rgb_color("triangle", line);
	obj = object_new(TRI, NULL, reflect);
	obj->element = init_triangle(vec1, vec2, vec3);
	object_addback(&(*data)->object, obj);
	return (obj);
}
