/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:14:48 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 11:14:54 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static void	input_vec_t(int idx, double input, t_vec *vec)
{
	if (idx == 0)
		vec->x = input;
	else if (idx == 1)
		vec->y = input;
	else if (idx == 2)
		vec->z = input;
}

t_color	get_rgb_color(char *err_point, char **line)
{
	t_color	color;
	double	a_color;
	int		idx;
	char	*start;

	idx = 0;
	skip_white_space(line);
	while (idx < 3)
	{
		if (ft_isdigit(**line) != TRUE)
			rt_error_handler(err_point, "invalid format", 1);
		start = *line;
		a_color = ft_strtod(*line, line);
		if ((*line - start > 2 && a_color == 0) || !is_char_range(a_color))
			rt_error_handler(err_point, "invalid arguments", 127);
		input_vec_t(idx, a_color, &color);
		idx++;
		if (**line != '\0' && **line == ',')
			(*line)++;
	}
	color = vec_div(color, 256);
	return (color);
}

t_point	get_3d_coordinates(char *err_point, char **line)
{
	t_point	coordinates;
	int		idx;
	double	point;

	idx = 0;
	skip_white_space(line);
	while (idx < 3)
	{
		if (ft_isdigit(**line) != TRUE && **line != '-' && **line != '+')
			rt_error_handler(err_point, "invalid format", 1);
		point = ft_strtod(*line, line);
		input_vec_t(idx, point, &coordinates);
		if (idx != 2 && **line == ',')
			(*line)++;
		idx++;
	}
	return (coordinates);
}

t_vec	get_vector(char *err_point, char **line)
{
	t_vec	vec;

	vec = get_3d_coordinates(err_point, line);
	if (!(-1 <= vec.x && vec.x <= 1))
		rt_error_handler(err_point, "invalid format", 1);
	if (!(-1 <= vec.y && vec.y <= 1))
		rt_error_handler(err_point, "invalid format", 1);
	if (!(-1 <= vec.z && vec.z <= 1))
		rt_error_handler(err_point, "invalid format", 1);
	return (vec);
}
