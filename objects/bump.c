/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:17:59 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/30 17:32:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "minirt.h"

//static char	*text_address(char *addr, int x, int y, t_vars *vars);
//static void	draw_sphere(t_vars *vars, t_point point, t_sphere *sp, char *addr);

//t_color	bump_color(t_vars *vars, t_point point, t_sphere *sp)
//{
//	void	*img;
//	char	*addr;

//	img = mlx_xpm_file_to_image(vars->mlx, "../earth.xpm", 1000, 500);
//	addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
//	&vars->line_length, &vars->endian);
//	draw_sphere(vars, point, sp, addr);
//}

//char	*text_address(char *addr, int x, int y, t_vars *vars)
//{
//	char	*dst;

//	dst = addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
//	return (*(unsigned int*)dst);
//}

//void	draw_sphere(t_vars *vars, t_point point, t_sphere *sp, char *addr)
//{
//	double	theta;
//	double	phi;
//	double	distance;

//	double dx = vars->pix_x - WIDTH / 2;
//	double dy = vars->pix_y - HEIGHT / 2;
//	distance = sqrt(dx * dx + dy * dy);
//	theta = atan2(dy, dx);
//	phi = acos(distance / sp->radius_square);
//	int tx = (int)((theta / (2 * M_PI) + 0.5) * 1000) % 1000;
//	int ty = (int)((phi / M_PI) * 500) % 500;
//	unsigned int color = text_address(addr, tx, ty, vars);
//	my_mlx_pixel_put(&vars->img, vars->pix_x, vars->pix_y, color);
//}

t_color	change_radix(char *dst);

t_color	calctexture(t_sphere *sp, t_container	*scene, t_vars *vars)
{
	double	dx;
	double	dy;
	t_vec	p;
	char	*dst;
	t_vars	*texture = NULL;
	int		img_width = 1000;
	int		img_height = 500;

	texture->img = mlx_xpm_file_to_image(vars->mlx, "../earth.xpm", &img_width, &img_height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	p = vec_minus_vec(scene->rec.point, sp->center);
	double theta = atan2(p.y, p.x); // 경도
	double phi = acos(p.z / sp->radius); // 위도
	dx = (int)((theta / (2 * M_PI) + 0.5) * 1000) % 1000;
	dy = (int)((phi / M_PI) * 500) % 500;
	dst = texture->addr + ((int)dy * texture->line_length + (int)dx * (texture->bits_per_pixel / 8));
	return (change_radix(dst));
}

t_color	change_radix(char *dst)
{
	int		ret = 1;
	int		check = 1;
	int		temp;
	int		i = 0;
	t_color	change;

	while (dst[i] != '\0')
	{
		if ('0' <= dst[i] && dst[i] <= '9')
			temp = dst[i] - '0';
		else if ('A' <= dst[i] && dst[i] <= 'F')
			temp = dst[i] - 'A';
		ret *= 16;
		check *= 16;
		ret += temp;
		i++;
	}
	ret -= check;
	change.z = (ret % 256) / 256;
	ret /= 256;
	change.y = (ret % 256) / 256;
	ret /= 256;
	change.x = (ret % 256) / 256;
	return (change);
}