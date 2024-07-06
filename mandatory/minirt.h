/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:45:25 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/05 17:03:58 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include "rt_parser.h"

enum {
	RED = 0,
	GREEN,
	BLUE,
} ;

int		key_hook(int keycode, t_vars *vars);
int		exit_hook(void);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

#endif