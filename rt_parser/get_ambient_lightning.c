/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_lightning.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:05:14 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/04 04:51:28 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_color	*get_ambient_lightning(char **line)
{
	t_color	*ambient;
	double	ratio;

	if (**line != 'A')
		return (NULL);
	(*line)++;
	ambient = (t_color *)ft_calloc(1, sizeof(t_color));
	if (ambient == NULL)
		rt_error_handler("ambient", "ft_calloc failed", 9);
	ratio = get_ratio(line);
	*ambient = get_rgb_color("ambient", line);
	*ambient = vec_mult_scal(*ambient, ratio);
	skip_white_space(line);
	return (ambient);
}
