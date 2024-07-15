/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:56:55 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/15 14:58:11 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	prt_pixel(t_vars *vars, t_container *scene);
void	calc_color(t_container *scene, double pixel_x, \
					double pixel_y, t_vars *vars);

void	print_color(t_color *color, int pixel_x, int pixel_y, t_vars *vars)
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
	t_vars		vars;

	data = minirt_parser(argc, argv);
	if (data == NULL)
		exit (1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "miniRT");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
	&vars.line_length, &vars.endian);
	prt_pixel(&vars, data);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
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

void	calc_color(t_container *scene, double pixel_x, \
					double pixel_y, t_vars *vars)
{
	double	x_weight;
	double	y_weight;
	t_color	pixel_color;

	x_weight = (double)pixel_x / (scene->canvas.width - 1);
	y_weight = 1 - (double)pixel_y / (scene->canvas.height - 1);
	scene->ray = ray_primary(scene->camera, x_weight, y_weight);
	pixel_color = ray_color(scene);
	print_color(&pixel_color, pixel_x, pixel_y, vars);
}
