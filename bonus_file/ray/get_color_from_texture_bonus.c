/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_texture_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:39:32 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

t_vec	get_color_from_texture(t_img *img, double u, double v)
{
	int		x;
	int		y;
	int		offset;
	t_vec	color;

	u = clamp(u, 0.0, 1.0);
	v = clamp(v, 0.0, 1.0);
	x = (int)(u * (img->width - 1));
	y = (int)(v * (img->height - 1));
	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (offset < 0 || offset >= img->line_length * img->height)
		rt_error_handler("texture mapping", "invalid offset", 1);
	color.x = (*(unsigned char *)(img->addr + offset + 2)) / 256.0;
	color.y = (*(unsigned char *)(img->addr + offset + 1)) / 256.0;
	color.z = (*(unsigned char *)(img->addr + offset + 0)) / 256.0;
	return (color);
}
