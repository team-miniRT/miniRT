/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:40:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/09 17:13:43 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_camera	*get_camera_data(char **line)
{
	t_camera	*cam;
	t_point		origin;
	t_vec		vec;
	int			fov;

	(*line)++;
	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (cam == NULL)
		rt_error_handler("camera", "ft_calloc failed", 9);
	origin = get_3d_coordinates("camera", line);
	vec = get_vector("camera", line);
	fov = ft_strtol(*line, line, 10);
	if (!(0 <= fov && fov <= 180))
		rt_error_handler("camera", "fov is not valid argumet", 1);
	cam->focal_len = fov;
	cam->orig = origin;
	cam->ray_dir = vec;
	return (cam);
}
