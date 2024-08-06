/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utiles_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/08/06 16:08:10 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILES_BONUS_H
# define RT_UTILES_BONUS_H

# include "keyhook_bonus.h"

typedef enum e_skin
{
	e_default = 0x00,
	e_check = 0x01,
	e_img = 0x02,
}	t_skin;

int		is_char_range(int nbr);
double	clamp(double value, double min, double max);

#endif