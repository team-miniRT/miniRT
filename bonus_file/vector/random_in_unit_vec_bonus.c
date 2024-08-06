/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_in_unit_vec_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:34:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

static double	random_double_range(double min, double max)
{
	return (min + (max - min) * (double)rand() / (double)RAND_MAX);
}

t_vec	random_in_unit_vec(void)
{
	int		idx;
	t_vec	ran_vec;

	idx = FALSE;
	ran_vec = make_vec(random_double_range(-1, 1), \
				random_double_range(-1, 1), random_double_range(-1, 1));
	while (idx == FALSE || vec_len(ran_vec) >= 1.0)
	{
		ran_vec = make_vec(random_double_range(-1, 1), \
				random_double_range(-1, 1), random_double_range(-1, 1));
		idx = TRUE;
	}
	return (ran_vec);
}
