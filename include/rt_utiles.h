/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utiles.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/07/06 23:45:43 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILES_H
# define RT_UTILES_H

# include "keyhook.h"

typedef enum e_skin
{
	e_default = 0x00,
	e_check = 0x01,
}	t_skin;

int	is_char_range(int nbr);

#endif