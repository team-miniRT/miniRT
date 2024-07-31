/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utiles.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/31 11:42:21 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILES_H
# define RT_UTILES_H

# include "keyhook.h"

typedef enum e_skin
{
	e_default = 0x00,
	e_check = 0x01,
	e_img = 0x02,
}	t_skin;

int	is_char_range(int nbr);
double	clamp(double value, double min, double max);

#endif