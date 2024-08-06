/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:56:55 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/06 16:06:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	prt_pixel(t_vars *vars, t_container *scene);
void	calc_color(t_container *scene, double pixel_x, \
					double pixel_y, t_vars *vars);

void	print_color(t_vec *color, int pixel_x, int pixel_y, t_vars *vars)
{
	int	num;
	int	red;
	int	green;
	int	blue;

	red = (int)((color->x) * (255.999)) << 16;
	green = (int)((color->y * (255.999))) << 8;
	blue = (int)((color->z) * (255.999));
	num = red + green + blue;
	my_mlx_pixel_put(vars, pixel_x, pixel_y, num);
}

int	main(int argc, char *argv[])
{
	t_container	*data;

	data = minirt_parser(argc, argv);
	if (data == NULL)
		exit (1);
	prt_pixel(&data->vars, data);
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, \
							data->vars.img, 0, 0);
	mlx_key_hook(data->vars.win, key_hook, &data->vars);
	mlx_hook(data->vars.win, 17, 0, exit_hook, 0);
	mlx_loop(data->vars.mlx);
	exit (0);
}

void	prt_pixel(t_vars *vars, t_container *scene)
{
	double		pixel_x;
	double		pixel_y;

	pixel_y = -1;
	while (++pixel_y < scene->canvas.height)
	{
		pixel_x = -1;
		while (++pixel_x < scene->canvas.width)
		{
			calc_color(scene, pixel_x, pixel_y, vars);
		}
	}
}

t_vec	calc_color_point(t_container *scene, double pixel_x, double pixel_y)
{
	t_vec	pixel_color;
	double	x_weight;
	double	y_weight;

	x_weight = (pixel_x) / (scene->canvas.width - 1);
	y_weight = 1 - (pixel_y) / (scene->canvas.height - 1);
	scene->ray = ray_primary(scene->camera, x_weight, y_weight);
	pixel_color = ray_color(scene);
	return (pixel_color);
}

void	calc_color(t_container *scene, double pixel_x, \
					double pixel_y, t_vars *vars)
{
	t_vec	pixel_color1;
	t_vec	pixel_color2;

	pixel_color1 = calc_color_point(scene, pixel_x + 0.4999, pixel_y + 0.4999);
	pixel_color2 = calc_color_point(scene, pixel_x, pixel_y + 0.4999);
	pixel_color2 = vec_plus_vec(pixel_color1, pixel_color2);
	pixel_color1 = calc_color_point(scene, pixel_x, pixel_y);
	pixel_color2 = vec_plus_vec(pixel_color1, pixel_color2);
	pixel_color1 = calc_color_point(scene, pixel_x + 0.4999, pixel_y);
	pixel_color2 = vec_plus_vec(pixel_color1, pixel_color2);
	pixel_color2 = vec_mult_scal(pixel_color2, 0.25);
	print_color(&pixel_color2, pixel_x, pixel_y, vars);
}
