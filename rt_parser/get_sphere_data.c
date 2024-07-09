/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:41:53 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/06 22:48:42 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_object	*get_sphere_data(t_container **data, char **line)
{
	t_object	*obj;
	t_sphere	*sphere;
	t_color		reflect;

	(*line) += 2;
	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (sphere == NULL)
		rt_error_handler("sphere", "ft_calloc failed", 9);
	sphere->center = get_3d_coordinates("sphere", line);
	sphere->radius = get_meter(line);
	sphere->radius_square = pow(sphere->radius, 2);
	reflect = get_rgb_color("sphere", line);
	obj = object_new(SP, sphere, reflect);
	object_addback(&(*data)->object, obj);
	return (obj);
}
