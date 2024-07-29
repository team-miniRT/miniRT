/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:18:20 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/29 20:56:58 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

int	get_skin_type(char **line)
{
	skip_white_space(line);
	if (**line == '\0')
		return (e_default);
	if (ft_strncmp(*line, "CHECKER", 6) == 0)
	{
		(*line) += 7;
		return (e_check);
	}
	// if (**line != '\0')
	// 	return (e_img);
	skip_white_space(line);
	return (0);
}
