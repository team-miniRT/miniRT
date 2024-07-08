/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:45:25 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/08 20:43:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include "rt_parser.h"

# define RED 0
# define GREEN 1
# define BLUE 2

int		main(int argc, char *argv[]);
int		key_hook(int keycode, t_vars *vars);
int		exit_hook(void);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

#endif