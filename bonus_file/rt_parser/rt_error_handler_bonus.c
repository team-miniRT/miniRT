/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:29:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser_bonus.h"

int	rt_error_handler(char *filename, char *error_msg, int error_code)
{
	char	*str_err;

	str_err = NULL;
	ft_dprintf(2, "miniRT: ");
	if (filename != NULL)
		ft_dprintf (2, "%s: ", filename);
	if (error_code != 0 && errno != 0)
	{
		str_err = strerror(errno);
		ft_dprintf (2, "%s", str_err);
	}
	else if (error_msg != NULL)
		ft_dprintf (2, "%s", error_msg);
	ft_dprintf (2, "\n");
	if (error_code != 0)
		exit(error_code);
	else
		exit(1);
}
