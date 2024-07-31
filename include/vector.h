/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:33:11 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 02:35:03 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "structor.h"

t_vec	make_vec(double x, double y, double z);
t_color	make_color(double x, double y, double z);
t_point	make_point(double x, double y, double z);
void	set_vector(t_vec *vec, double x, double y, double z);
double	vec_inner_pro(t_vec vec1, t_vec vec2);
t_vec	vec_outer_pro(t_vec vec1, t_vec vec2);
double	vec_len_square(t_vec vec);
double	vec_len(t_vec vec);
t_vec	vec_unit(t_vec vec);
t_vec	vec_min(t_vec vec1, t_vec vec2);
t_vec	vec_plus_vec(t_vec vec1, t_vec vec2);
t_vec	vec_plus_scal(t_vec vec, double x, double y, double z);
t_vec	vec_minus_vec(t_vec vec1, t_vec vec2);
t_vec	vec_minus_scal(t_vec vec, double x, double y, double z);
t_vec	vec_mult_vec(t_vec vec1, t_vec vec2);
t_vec	vec_mult_scal(t_vec vec, double k);
t_vec	vec_div(t_vec vec, double t);
double	point_to_point(t_point p1, t_point p2);
void	print_point(t_vec v);
t_vec	vec_rotate(t_vec vec, t_vec axis, double theta);
t_vec	random_in_unit_vec(void);

#endif