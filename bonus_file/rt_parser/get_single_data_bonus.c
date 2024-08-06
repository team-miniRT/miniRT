/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single_data_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:37:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser_bonus.h"

double	get_meter(char **line)
{
	double	meter;

	skip_white_space(line);
	meter = ft_strtod(*line, line);
	if (ft_isalpha(**line) == TRUE)
		rt_error_handler("meter", "invalid arguments", 127);
	if (meter <= 0)
		rt_error_handler("meter", "It must be positive", 1);
	return (meter);
}

double	get_ratio(char **line)
{
	double	ratio;

	skip_white_space(line);
	ratio = ft_strtod(*line, line);
	if (!(0 <= ratio && ratio <= 1))
		rt_error_handler("ratio", "invalid arguments", 127);
	return (ratio);
}
