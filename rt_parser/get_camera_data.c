/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:40:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/09 23:43:08 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_camera	*get_camera_data(char **line, t_container **data)
{
	t_camera	*cam;
	t_point		origin;
	t_vec		vec;
	int			fov;
	double		viewport_height;

	(*line)++;
	viewport_height = 2.0;
	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (cam == NULL)
		rt_error_handler("camera", "ft_calloc failed", 9);
	origin = get_3d_coordinates("camera", line);
	vec = get_vector("camera", line);
	fov = ft_strtol(*line, line, 10);
	if (!(0 <= fov && fov <= 180))
		rt_error_handler("camera", "fov is not valid argumet", 1);
	cam->focal_len = 0.5;
	cam->orig = origin;
	cam->ray_dir = vec;
	cam->viewport_h = viewport_height;
	cam->viewport_w = viewport_height * (*data)->canvas.aspect_ratio;
	cam->horizontal = make_vec(cam->viewport_w, 0, 0);
	cam->vertical = make_vec(0, cam->viewport_h, 0);
	cam->left_bottom = vec_minus_vec(vec_minus_vec(vec_minus_vec(cam->orig, \
	vec_div(cam->horizontal, 2)), vec_div(cam->vertical, 2)), \
	make_vec(0, 0, cam->focal_len));
	return (cam);
}
