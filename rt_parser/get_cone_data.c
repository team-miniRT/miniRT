/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:48:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 11:36:25 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static t_vec	get_next_vertex(int idx, t_vec base_point, double r)
{
	double	angle;
	t_vec	res;
	t_vec	d_dir;

	d_dir = make_point(0, -1, 0);
	angle = (2 * M_PI) / CONE_N * (idx + 1);
	res.x = base_point.x + r * cos(angle);
	res.y = base_point.y;
	res.z = base_point.z + r * sin(angle);
	return (res);
}

static t_vec	rotate_around_point(t_vec point, t_vec origin, \
									t_vec axis, double theta)
{
	t_vec	translated_point;
	t_vec	rotated_point;

	translated_point = vec_minus_vec(point, origin);
	rotated_point = vec_rotate(translated_point, axis, theta);
	return (vec_plus_vec(rotated_point, origin));
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
	t_vec	base_point;
	t_vec	vec2;
	t_vec	vec3;
	t_vec	rotated_base;
	int		idx;

	base_point = vec_plus_scal(cone.origin, \
				0, -1 * cone.unit_vec.y * cone.height, 0.0);
	rotated_base = rotate_around_point(base_point, cone.origin, \
										cone.unit_vec, M_PI / 4);
	vec2 = get_next_vertex(-1, base_point, cone.radius);
	vec2 = rotate_around_point(vec2, cone.origin, cone.unit_vec, M_PI / 4);
	idx = 0;
	while (idx < CONE_N)
	{
		vec3 = get_next_vertex(idx, base_point, cone.radius);
		vec3 = rotate_around_point(vec3, cone.origin, cone.unit_vec, M_PI / 4);
		add_triangle_to_container(cone, cone.origin, vec2, vec3);
		add_triangle_to_container(cone, rotated_base, vec2, vec3);
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
	cone.origin = vec_minus_vec(cone.origin, (*data)->camera->orig);
	cone.unit_vec = get_vector("cone", line);
	cone.radius = get_meter(line) / 2;
	cone.height = get_meter(line);
	cone.reflect = get_rgb_color("cone", line);
	init_cone(cone);
}
