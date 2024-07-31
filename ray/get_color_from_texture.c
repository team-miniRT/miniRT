/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:39:32 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 11:47:04 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_color	get_color_from_texture(t_img *img, double u, double v)
{
	int		x;
	int		y;
	int		offset;
	t_color	color;

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
