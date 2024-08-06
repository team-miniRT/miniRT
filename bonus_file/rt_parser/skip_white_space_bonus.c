/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_white_space_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:18:42 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser_bonus.h"

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
	if (is_comment(line))
		skip_string(line);
}
