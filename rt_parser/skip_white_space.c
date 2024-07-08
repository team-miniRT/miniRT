/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_white_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:18:42 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/01 16:17:18 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static int	ft_is_whitespace(char c)
{
	if (c == ' ')
		return (TRUE);
	if (8 < c && c < 14)
		return (TRUE);
	return (FALSE);
}

void	skip_white_space(char **line)
{
	while (**line != '\0')
	{
		if (ft_is_whitespace(**line) != TRUE)
			break ;
		(*line)++;
	}
}
