/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_data_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:40:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/08 14:24:18 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser_bonus.h"

static void	set_cam_data(t_vec vec, double half_width, double half_height, \
							t_container **data)
{
	t_vec	u;
	t_vec	v;
	t_vec	up;

	up = make_vec(0, 1, 0);
	vec = vec_unit(vec_minus_vec(make_vec(0, 0, 0), vec));
	if (fabs(vec_inner_pro(up, vec)) > 0.999)
		up = make_vec(1, 0, 0);
	u = vec_unit(vec_outer_pro(up, vec));
	v = vec_outer_pro(vec, u);
	(*data)->camera->horizontal = vec_mult_scal(u, 2 * half_width);
	(*data)->camera->vertical = vec_mult_scal(v, 2 * half_height);
	(*data)->camera->left_bottom = vec_minus_vec(vec_minus_vec(\
			vec_minus_vec(make_vec(0, 0, 0), \
			vec_div((*data)->camera->horizontal, 2)), \
			vec_div((*data)->camera->vertical, 2)), vec);
	(*data)->camera->viewport_h = 1.0 * half_height;
	(*data)->camera->viewport_w = 1.0 * half_width;
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
	(*data)->camera->orig = get_3d_coordinates("camera", line);
	vec = get_vector("camera", line);
	get_aspect_ratio(vec, line, data);
	(*data)->camera->cam_num++;
	return ((*data)->camera);
}
