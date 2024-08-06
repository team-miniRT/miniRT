/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_unit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:00:39 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

double	vec_len_square(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_len(t_vec vec)
{
	return (sqrt(vec_len_square(vec)));
}

t_vec	vec_unit(t_vec vec)
{
	double	len;

	len = vec_len(vec);
	if (len == 0)
	{
		return (vec);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
