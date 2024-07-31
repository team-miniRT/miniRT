/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:41:53 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 10:18:15 by jjhang           ###   ########.fr       */
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
	sphere->center = vec_minus_vec(sphere->center, (*data)->camera->orig);
	sphere->radius = get_meter(line) / 2;
	sphere->radius_square = pow(sphere->radius, 2);
	reflect = get_rgb_color("sphere", line);
	obj = object_new(SP, sphere, reflect);
	obj->skin = get_skin_type(line);
	if (obj->skin == e_img)
		obj->img = get_img_file(data, "./xpm_files/earth.xpm");
	object_addback(&(*data)->object, obj);
	return (obj);
}
