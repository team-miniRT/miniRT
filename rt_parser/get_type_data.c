/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:18:20 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/30 16:49:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

int	get_skin_type(char **line)
{
	skip_white_space(line);
	if (**line == '\0')
		return (e_default);
	if (ft_strncmp(*line, "CHECKER", 7) == 0)
	{
		(*line) += 7;
		return (e_check);
	}
	else if (ft_strncmp(*line, "EARTH", 5) == 0)
	{
		(*line) += 5;
		return (e_img);
	}
	skip_white_space(line);
	return (0);
}
