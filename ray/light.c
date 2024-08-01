/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:06:31 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 12:08:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_light	*light_point(t_vec light_origin, t_vec light_color, \
					double bright_ratio)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		exit(1);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
