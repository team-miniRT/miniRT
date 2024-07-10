/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:40:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/10 13:40:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

// t_camera	*get_camera_data(char **line, t_container **data)
// {
// 	t_camera	*cam;
// 	t_point		origin;
// 	t_vec		vec;
// 	int			fov;
// 	double		viewport_height;

// 	(*line)++;
// 	viewport_height = 2.0;
// 	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
// 	if (cam == NULL)
// 		rt_error_handler("camera", "ft_calloc failed", 9);
// 	origin = get_3d_coordinates("camera", line);
// 	vec = get_vector("camera", line);
// 	fov = ft_strtol(*line, line, 10);
// 	if (!(0 <= fov && fov <= 180))
// 		rt_error_handler("camera", "fov is not valid argumet", 1);
// 	cam->focal_len = 0.5;
// 	cam->orig = origin;
// 	cam->ray_dir = vec;
// 	cam->viewport_h = viewport_height;
// 	cam->viewport_w = viewport_height * (*data)->canvas.aspect_ratio;
// 	cam->horizontal = make_vec(cam->viewport_w, 0, 0);
// 	cam->vertical = make_vec(0, cam->viewport_h, 0);
// 	cam->left_bottom = vec_minus_vec(vec_minus_vec(vec_minus_vec(cam->orig, \
// 	vec_div(cam->horizontal, 2)), vec_div(cam->vertical, 2)), \
// 	make_vec(0, 0, cam->focal_len));
// 	return (cam);
// }

double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180.0);
}

t_vec	vec_unit_vector(t_vec v)
{
	double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (t_vec){v.x / length, v.y / length, v.z / length};
}

t_vec	vec_cross(t_vec a, t_vec b)
{
	return (t_vec){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}

t_vec vec_mul_scalar(t_vec v, double scalar)
{
	return (t_vec){v.x * scalar, v.y * scalar, v.z * scalar};
}

t_camera	*get_camera_data(char **line, t_container **data)
{
	t_camera	*cam;
	t_point		origin;
	t_vec		vec;
	int			fov;
	double		aspect_ratio;
	double		theta;
	double		half_height;
	double		half_width;
	t_vec		w;
	t_vec		u;
	t_vec		v;

	(*line)++;
	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (cam == NULL)
		rt_error_handler("camera", "ft_calloc failed", 9);
	origin = get_3d_coordinates("camera", line);
	vec = get_vector("camera", line);
	fov = ft_strtol(*line, line, 10);
	if (!(0 <= fov && fov <= 180))
		rt_error_handler("camera", "fov is not valid argument", 1);
	aspect_ratio = (*data)->canvas.aspect_ratio;
	theta = degrees_to_radians(fov);
	half_height = tan(theta / 2);
	half_width = aspect_ratio * half_height;
	w = vec_unit_vector(vec_minus_vec(origin, vec));
	u = vec_unit_vector(vec_cross(make_vec(0, 1, 0), w));
	v = vec_cross(w, u);
	cam->orig = origin;
	cam->horizontal = vec_mul_scalar(u, 2 * half_width);
	cam->vertical = vec_mul_scalar(v, 2 * half_height);
	cam->left_bottom = vec_minus_vec(vec_minus_vec(vec_minus_vec(cam->orig, vec_div(cam->horizontal, 2)), vec_div(cam->vertical, 2)), w);
	cam->viewport_h = 2.0 * half_height;
	cam->viewport_w = 2.0 * half_width;
	return (cam);
}
