/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:44:36 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/30 18:43:21 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parser.h"

t_img	*get_img_file(t_container **data, char *filepath)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (img == NULL)
		rt_error_handler("get_img_file", NULL, 1);
	img->img = mlx_xpm_file_to_image((*data)->vars.mlx, \
						filepath, &img->width, &img->height);
	if (img->img == NULL)
		rt_error_handler("get_img_files", NULL, 1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_length, &img->endian);
	return (img);
}
