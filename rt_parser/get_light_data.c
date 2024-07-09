/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 05:59:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/06 22:42:10 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_object	*get_light_data(t_container **data, char **line)
{
	t_light		*light;
	t_object	*obj;
	t_color		reflect;

	(*line)++;
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (light == NULL)
		rt_error_handler("light", "ft_calloc failed", 9);
	light->origin = get_3d_coordinates("light", line);
	light->bright_ratio = get_ratio(line);
	skip_white_space(line);
	if (**line != '\0')
		reflect = get_rgb_color("light", line);
	else
		reflect = make_color(255, 255, 255);
	obj = object_new(LIGHT_POINT, light, reflect);
	object_addback(&(*data)->light, obj);
	return (obj);
}
