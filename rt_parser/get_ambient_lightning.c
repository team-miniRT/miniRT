/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_lightning.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:05:14 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/01 13:40:33 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_vec	*get_ambient_lightning(char **line, t_container **data)
{
	t_vec	*ambient;
	double	ratio;

	if (**line != 'A')
		return (NULL);
	(*line)++;
	ambient = (t_vec *)ft_calloc(1, sizeof(t_vec));
	if (ambient == NULL)
		rt_error_handler("ambient", "ft_calloc failed", 9);
	ratio = get_ratio(line);
	(*data)->ratio = ratio;
	*ambient = get_rgb_color("ambient", line);
	*ambient = vec_mult_scal(*ambient, ratio);
	skip_white_space(line);
	return (ambient);
}
