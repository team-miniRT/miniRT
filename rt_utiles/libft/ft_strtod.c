/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:23:57 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/04 05:55:44 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_integer(char **str, double *sign)
{
	double	acc;

	acc = 0.0;
	while (**str != '\0' && **str != '.' && \
				(**str == ' ' || (8 < **str && **str < 13)))
		(*str)++;
	while (**str != '\0' && (**str == '-' || **str == '+'))
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
	while (**str != '\0' && **str != '.' && ft_isdigit(**str) == 1)
	{
		acc = acc * 10 + (**str - '0');
		(*str)++;
	}
	return (acc);
}

double	ft_strtod(char *str, char **end_ptr)
{
	double	acc;
	double	idx;
	double	sign;

	acc = 0.0;
	sign = 1.0;
	acc = get_integer(&str, &sign);
	if (*str == '.')
		str++;
	idx = 0.1;
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		acc = acc + (double)((*str - '0') * idx);
		idx *= 0.1;
		str++;
	}
	if (end_ptr != NULL)
		*end_ptr = str;
	return (sign * acc);
}
