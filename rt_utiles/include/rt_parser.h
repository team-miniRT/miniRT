/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:58:15 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/05 16:40:02 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
# define RT_PARSER_H

# define FALSE 0
# define TRUE 1
# define ERROR -1

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
	t_canvas		canvas;
	t_color			*ambient;
	t_camera		*camera;
	t_object		*light;
	t_object		*object;
	t_ray			ray;
	t_hit_record	rec;
}	t_container;

int			 main(int argc, char *argv[]);
t_container	*minirt_parser(int argc, char *argv[]);
/* srcs */
int			is_valid_file(int argc, char *argv[]);
t_color		*get_ambient_lightning(char **line);
t_camera	*get_camera_data(char **line);
t_object	*get_light_data(t_container **data, char **line);
t_object	*get_sphere_data(char **line);
/* utiles */
t_color		get_rgb_color(char *err_point, char **line);
t_point		get_3d_coordinates(char *err_point, char **line);
t_vec		get_vector(char *err_point, char **line);
double		get_ratio(char **line);
double		get_meter(char **line);
void		skip_white_space(char **line);
int			rt_error_handler(char *filename, char *error_msg, int error_code);
t_object	*new_object(t_object_type type, void *element, t_color reflect);
t_object	*get_t_object(t_object_type type, \
							void *element, t_container **data, char **line);

#endif