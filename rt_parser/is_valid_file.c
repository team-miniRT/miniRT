/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:42:26 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/30 16:09:13 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

static int	is_valid_file_extention(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (ERROR);
	if (ft_strcmp(&filename[len - 3], ".rt") != 0)
		return (ERROR);
	if (len == 4 && filename[0] == '.')
		return (ERROR);
	return (0);
}

static int	is_valid_file_permission(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	close(fd);
	return (0);
}

int	is_valid_file(int argc, char *argv[])
{
	if (argc != 2)
		rt_error_handler(argv[1], "Invalid argument", 22);
	if (is_valid_file_extention(argv[1]) == ERROR)
		rt_error_handler(argv[1], "Is not valid file extention", 1);
	if (is_valid_file_permission(argv[1]) == ERROR)
		rt_error_handler(argv[1], "file does not exist/Permission denied", 13);
	return (0);
}
