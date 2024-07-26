/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:48:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/26 18:53:08 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_vec	get_next_vertex(int idx, t_vec base_point, double r)
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

t_vec rotate_around_point(t_vec point, t_vec origin, t_vec axis, double theta)
{
	t_vec translated_point;
	t_vec rotated_point;

	translated_point = vec_minus_vec(point, origin);
	rotated_point = vec_rotate(translated_point, axis, theta);
	return (vec_plus_vec(rotated_point, origin));
}

void	init_cone(t_point vec1, t_vec dir, t_color reflect, t_vec meter, t_container **data)
{
	t_object	*obj;
	t_vec		base_point;
	t_vec		vec2;
	t_vec		vec3;
	int			idx;

	idx = 0;
	base_point = vec_plus_scal(vec1, 0, -1 * meter.y, 0.0);
	vec2 = get_next_vertex(-1, base_point, meter.x);
	vec2 = rotate_around_point(vec2, vec1, dir, M_PI / 4);
	obj = NULL;
	while (idx < CONE_N)
	{
		vec3 = get_next_vertex(idx, base_point, meter.x);
		vec3 = rotate_around_point(vec3, vec1, dir, M_PI / 4);
		obj = ft_calloc(1, sizeof(t_object));
		obj->element = init_triangle(vec1, vec2, vec3);
		obj->type = TRI;
		obj->reflect = reflect;
		object_addback(&(*data)->object, obj);
		vec2 = vec3;
		idx++;
	}
}

 void	get_cone_data(t_container **data, char **line)
{
	t_point		points;
	t_vec		vec;
	t_vec		meter;
	t_color		reflect;

	(*line) += 4;
	points = get_3d_coordinates("cone", line);
	vec = get_vector("cone", line);
	meter.x = get_meter(line) / 2;
	meter.y = get_meter(line);
	meter.z = 0;
	reflect = get_rgb_color("cone", line);
	init_cone(points, vec, reflect, meter, data);
}
