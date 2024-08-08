/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_in_unit_vec_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:34:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/08 21:50:01 by yeoshin          ###   ########.fr       */
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
	return (ran_vec);
}
