/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:48:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/02 10:30:26 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static t_vec get_next_vertex(int idx, t_vec base_point, double r, t_vec axis)
{
	double angle;
	t_vec res;

	angle = (2 * M_PI) / CONE_N * (idx + 1);
	if (axis.x == 1.0)
	{
		res.x = base_point.x;
		res.y = base_point.y + r * cos(angle);
		res.z = base_point.z + r * sin(angle);
	} else if (axis.y == 1.0)
	{
		res.x = base_point.x + r * cos(angle);
		res.y = base_point.y;
		res.z = base_point.z + r * sin(angle);
	} else
	{
		res.x = base_point.x + r * cos(angle);
		res.y = base_point.y + r * sin(angle);
		res.z = base_point.z;
	}
	return res;
}

static void	add_triangle_to_container(t_cone cone, t_vec p1, t_vec p2, t_vec p3)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	obj->element = init_triangle(p1, p2, p3);
	obj->type = TRI;
	obj->reflect = cone.reflect;
	object_addback(&cone.data->object, obj);
}

void	init_cone(t_cone cone)
{
	t_vec base_point;
	t_vec vec2;
	t_vec vec3;
	int idx;

	base_point = vec_plus_scal(cone.origin, \
							   -cone.unit_vec.x * cone.height, \
							   -cone.unit_vec.y * cone.height, \
							   -cone.unit_vec.z * cone.height);
	vec2 = get_next_vertex(-1, base_point, cone.radius, cone.unit_vec);
	idx = 0;
	while (idx < CONE_N) {
		vec3 = get_next_vertex(idx, base_point, cone.radius, cone.unit_vec);
		add_triangle_to_container(cone, cone.origin, vec2, vec3);
		vec2 = vec3;
		idx++;
	}
}


void	get_cone_data(t_container **data, char **line)
{
	t_cone		cone;

	(*line) += 4;
	cone.data = *data;
	cone.origin = get_3d_coordinates("cone", line);
	cone.unit_vec = get_vector("cone", line);
	cone.radius = get_meter(line) / 2;
	cone.height = get_meter(line);
	cone.reflect = get_rgb_color("cone", line);
	cone.origin = vec_plus_vec(cone.origin, \
					vec_mult_scal(cone.unit_vec, cone.height * 0.5));
	cone.origin = vec_minus_vec(cone.origin, (*data)->camera->orig);
	init_cone(cone);
}
