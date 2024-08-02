/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:57:40 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/02 09:19:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static void	obj_turnout(char **line, t_container **data)
{
	if (**line == 'A' && (*data)->ambient == NULL)
		(*data)->ambient = get_ambient_lightning(line, data);
	else if ((**line == 'A' && (*data)->ambient != NULL))
		rt_error_handler("ambient light", "only a argument is required.", 9);
	else if (**line == 'C' && (*data)->camera->cam_num == 0)
		get_camera_data(line, data);
	else if ((**line == 'C' && (*data)->camera->cam_num != 0))
		rt_error_handler("camera point", "only a argument is required.", 9);
	else if (**line == 'L')
		get_light_data(data, line);
	else if (ft_strncmp("cone", *line, 4) == 0)
		get_cone_data(data, line);
	else if (ft_strncmp("sp", *line, 2) == 0)
		get_sphere_data(data, line);
	else if (ft_strncmp("pl", *line, 2) == 0)
		get_plane_data(data, line);
	else if (ft_strncmp("cy", *line, 2) == 0)
		get_cylinder_data(data, line);
	else if (ft_strncmp("tri", *line, 2) == 0)
		get_triangle_data(data, line);
	else
		rt_error_handler("parse error near", *line, 127);
}

static void	input_data(char *line, t_container **data)
{
	while (*line != '\0')
	{
		skip_white_space(&line);
		if (*line == '\0')
			return ;
		obj_turnout(&line, data);
	}
}

static void	is_valid_rt_file(t_container *data)
{
	if (data->ambient == NULL)
		rt_error_handler("ambient", "Ambient light data is required", 0);
	if (data->camera->cam_num == 0)
	{
		rt_error_handler("camera", "Camera data is required", 0);
	}
	if (data->light == NULL)
		rt_error_handler("light", "At least one light data is required", 0);
}

static void	set_container(char *filename, t_container **data)
{
	char	*line;
	int		fd;
	int		idx;

	(*data)->canvas = canvas_init(WIDTH, HEIGHT);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		rt_error_handler(filename, "open failed", 1);
	line = NULL;
	idx = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		input_data(line, data);
		free(line);
		line = NULL;
		idx++;
	}
	is_valid_rt_file(*data);
}

t_container	*minirt_parser(int argc, char *argv[])
{
	t_container	*data;

	data = NULL;
	is_valid_file(argc, argv);
	data = (t_container *)ft_calloc(1, sizeof(t_container));
	if (data == NULL)
		rt_error_handler(argv[1], "Cannot allocate memory", 12);
	data->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (data->camera == NULL)
		rt_error_handler("camera", "ft_calloc failed", 9);
	data->vars.mlx = mlx_init();
	data->vars.win = mlx_new_window(data->vars.mlx, WIDTH, HEIGHT, "miniRT");
	data->vars.img = mlx_new_image(data->vars.mlx, WIDTH, HEIGHT);
	data->vars.addr = mlx_get_data_addr(data->vars.img, \
	&data->vars.bits_per_pixel, &data->vars.line_length, &data->vars.endian);
	set_container(argv[1], &data);
	data->camera->orig = vec_minus_vec(data->camera->orig, data->camera->orig);
	return (data);
}
