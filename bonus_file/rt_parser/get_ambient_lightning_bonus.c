/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_lightning_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:05:14 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/08 14:14:02 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser_bonus.h"

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
	(*data)->ambient = ambient;
	return (ambient);
}
