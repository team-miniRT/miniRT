/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:45:25 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/06 16:08:10 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "rt_parser_bonus.h"

# define RED 0
# define GREEN 1
# define BLUE 2

int		main(int argc, char *argv[]);
int		key_hook(int keycode, t_vars *vars);
int		exit_hook(void);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

#endif