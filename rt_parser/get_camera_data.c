/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:40:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/15 13:34:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static void	set_cam_data(t_vec vec, double half_width, double half_height, \
							t_container **data)
{
	t_vec	w;
	t_vec	u;
	t_vec	v;

	w = vec_unit(vec_minus_vec((*data)->camera->orig, vec));
	u = vec_unit(vec_outer_pro(make_vec(0, 1, 0), w));
	v = vec_outer_pro(w, u);
	(*data)->camera->horizontal = vec_mult_scal(u, 2 * half_width);
	(*data)->camera->vertical = vec_mult_scal(v, 2 * half_height);
	(*data)->camera->left_bottom = vec_minus_vec(vec_minus_vec(\
			vec_minus_vec((*data)->camera->orig, \
			vec_div((*data)->camera->horizontal, 2)), \
			vec_div((*data)->camera->vertical, 2)), w);
	(*data)->camera->viewport_h = 2.0 * half_height;
	(*data)->camera->viewport_w = 2.0 * half_width;
}

static void	get_aspect_ratio(t_vec vec, char **line, t_container **data)
{
	int		fov;
	double	theta;
	double	half_height;
	double	half_width;

	fov = ft_strtol(*line, line, 10);
	if (!(0 <= fov && fov <= 180))
		rt_error_handler("camera", "fov is not valid argument", 1);
	theta = fov * M_PI / 180.0;
	half_width = tan(theta / 2);
	half_height = (*data)->canvas.aspect_ratio * half_width;
	set_cam_data(vec, half_width, half_height, data);
}

t_camera	*get_camera_data(char **line, t_container **data)
{
	t_vec		vec;

	(*line)++;
	(*data)->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if ((*data)->camera == NULL)
		rt_error_handler("camera", "ft_calloc failed", 9);
	(*data)->camera->orig = get_3d_coordinates("camera", line);
	vec = get_vector("camera", line);
	get_aspect_ratio(vec, line, data);
	return ((*data)->camera);
}
