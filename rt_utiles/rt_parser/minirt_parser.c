/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:57:40 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/06 21:33:18 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static void	obj_turnout(char **line, t_container **data)
{
	if (**line == 'A' && (*data)->ambient == NULL)
	{
		(*data)->ambient = get_ambient_lightning(line);
		return ;
	}
	else if (**line == 'A' && (*data)->ambient != NULL)
		rt_error_handler("ambient light", "only a argument is required.", 9);
	if (**line == 'C' && (*data)->camera == NULL)
		(*data)->camera = get_camera_data(line);
	else if (**line == 'C' && (*data)->camera != NULL)
		rt_error_handler("camera point", "only a argument is required.", 9);
	if (**line == 'L')
		get_light_data(data, line);
	else if (ft_strncmp("sp", *line, 2) == 0)
		get_sphere_data(line);
	else if (ft_strncmp("pl", *line, 2) == 0)
		get_plane_data(line);
}

static void	input_data(char *line, t_container **data)
{
	while (*line != '\0')
	{
		skip_white_space(&line);
		obj_turnout(&line, data);
	}
}

static void	set_container(char *filename, t_container **data)
{
	char	*line;
	int		fd;

	(*data)->canvas = canvas_init(WIDTH, HEIGHT);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		rt_error_handler(filename, "open failed", 1);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		input_data(line, data);
		free(line);
		line = NULL;
	}
	/* edit camera origin vector*/
}

t_container	*minirt_parser(int argc, char *argv[])
{
	t_container	*data;

	data = NULL;
	is_valid_file(argc, argv);
	data = (t_container *)ft_calloc(1, sizeof(t_container));
	if (data == NULL)
		rt_error_handler(argv[1], "Cannot allocate memory", 12);
	set_container(argv[1], &data);
	return (data);
}

int main(int argc, char *argv[])
{
	t_container *data;

	data = minirt_parser(argc, argv);
	if (data == NULL)
		return (ERROR);
	printf ("ambient: %f %f %f\n", data->ambient->x, data->ambient->y, data->ambient->z);
	return (0);
}
