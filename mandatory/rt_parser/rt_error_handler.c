/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:29:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/02 09:17:51 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

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
