/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:40:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/05 16:22:26 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_camera	*get_camera_data(char **line)
{
	t_camera	*cam;
	t_point		origin;
	t_vec		vec;
	int			fov;

	if (**line != 'C')
		return (NULL);
	(*line)++;
	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (cam == NULL)
		rt_error_handler("camera", "ft_calloc failed", 9);
	origin = get_3d_coordinates("camera", line);
	vec = get_vector("camera", line);
	fov = ft_strtol(*line, line, 10);
	if (!(0 <= fov && fov <= 180))
		rt_error_handler("camera", "fov is not valid argumet", 1);
	cam->orig = origin;
	cam->vertical = vec;
	return (cam);
}
