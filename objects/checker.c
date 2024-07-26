/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:19:59 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/26 18:33:10 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int	checker_point(t_point p)
{
	int	hap;

	hap = 0;
	if (p.x >= 0 && (int)(p.x) % 2 > 0)
		hap += 1;
	else if (p.x < 0 && (int)(p.x) % 2 == 0)
		hap += 1;
	if (p.y >= 0 && (int)(p.y) % 2 > 0)
		hap += 1;
	else if (p.y < 0 && (int)(p.y) % 2 == 0)
		hap += 1;
	if (p.z >= 0 && (int)(p.z) % 2 > 0)
		hap += 1;
	else if (p.z < 0 && (int)(p.z) % 2 == 0)
		hap += 1;
	if (hap != 0)
	{
		if (hap > 1)
			return (TRUE);
		return (FALSE);
	}
	return (TRUE);

}
