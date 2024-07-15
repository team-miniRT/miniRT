/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:02:15 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/15 17:03:29 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

int	is_comment(char **line)
{
	if (*line == '#')
		return (1);
	return (0);
}

void	skip_string(char **line)
{
	while (**line != '\0')
		(*line)++;
}