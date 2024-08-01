/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:58:15 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/01 12:08:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
# define RT_PARSER_H

# define FALSE 0
# define TRUE 1
# define ERROR -1

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"
# include "structor.h"
# include "ray.h"
# include "vector.h"
# include "objects.h"
# include "hit.h"
# include "rt_utiles.h"

typedef struct s_container
{
	t_vars			vars;
	t_canvas		canvas;
	t_vec			*ambient;
	t_camera		*camera;
	t_object		*light;
	t_object		*object;
	t_ray			ray;
	t_hit_record	rec;
}	t_container;

typedef struct s_cone
{
	t_container	*data;
	t_vec		origin;
	t_vec		unit_vec;
	double		radius;
	double		height;
	t_vec		reflect;
}	t_cone;

t_container	*minirt_parser(int argc, char *argv[]);
/* srcs */
int			is_valid_file(int argc, char *argv[]);
t_vec		*get_ambient_lightning(char **line);
t_camera	*get_camera_data(char **line, t_container **data);
t_object	*get_triangle_data(t_container **data, char **line);
t_object	*get_light_data(t_container **data, char **line);
t_object	*get_sphere_data(t_container **data, char **line);
t_object	*get_plane_data(t_container **data, char **line);
t_object	*get_cylinder_data(t_container **data, char **line);
void		get_cone_data(t_container **data, char **line);
/* utiles */
t_vec		get_rgb_color(char *err_point, char **line);
t_vec		get_3d_coordinates(char *err_point, char **line);
t_vec		get_vector(char *err_point, char **line);
double		get_ratio(char **line);
double		get_meter(char **line);
void		skip_white_space(char **line);
int			rt_error_handler(char *filename, char *error_msg, int error_code);
int			is_comment(char **line);
void		skip_string(char **line);
int			get_skin_type(char **line);
t_img		*get_img_file(t_container **data, char *filepath);

#endif