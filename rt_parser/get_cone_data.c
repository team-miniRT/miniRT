/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:48:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/04 22:23:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static t_object	*add_triangle_to_container(t_cone cone, \
												t_vec p1, t_vec p2, t_vec p3)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	obj->element = init_triangle(p1, p2, p3);
	obj->type = TRI;
	obj->reflect = cone.reflect;
	object_addback(&cone.data->object, obj);
	return (obj);
}

void	init_cone(t_cone cone)
{
	t_object	*temp;
	t_object	*frist;
	t_vec 		vec2;
	t_vec 		vec3;
	int 		idx;

	vec2 = get_next_vertex(0, cone, cone.radius);
	idx = 0;
	while (idx < CONE_N)
	{
		vec3 = get_next_vertex(idx + 1, cone, cone.radius);
		temp = add_triangle_to_container(cone, cone.top, vec2, vec3);
		if (idx == 0)
			frist = temp;
		add_triangle_to_container(cone, cone.base_point, vec2, vec3);
		vec2 = vec3;
		idx++;
	}
}


void	get_cone_data(t_container **data, char **line)
{
	t_cone	cone;

	(*line) += 4;
	cone.data = *data;
	cone.center = get_3d_coordinates("cone", line);
	cone.unit_vec = get_vector("cone", line);
	cone.unit_vec = vec_unit(cone.unit_vec);
	cone.radius = get_meter(line) / 2;
	cone.height = get_meter(line);
	cone.reflect = get_rgb_color("cone", line);
	cone.center = vec_minus_vec(cone.center, (*data)->camera->orig);
	cone.top = vec_plus_vec(cone.center, \
					vec_mult_scal(cone.unit_vec, cone.height * 0.5));
	cone.base_point = vec_minus_vec(cone.top, \
					vec_mult_scal(cone.unit_vec, cone.height));
	init_cone(cone);
}
