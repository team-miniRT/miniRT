/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:14:02 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/30 20:29:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere	*init_sphere(t_point center, double radius)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	if (sp == NULL)
		exit(1);
	sp->center = center;
	sp->radius = radius;
	sp->radius_square = radius * radius;
	sp->x = 0;
	sp->y = 0;
	return (sp);
}

t_bool	get_discriminant(t_sphere *sp, double *root, \
						t_ray *ray, t_hit_record *rec)
{
	t_vec		oc;
	double		a;
	double		half_b;
	double		c;
	double		discri;

	oc = vec_minus_vec(ray->orig, sp->center);
	a = vec_len_square(ray->dir);
	half_b = vec_inner_pro(oc, ray->dir);
	c = vec_len_square(oc) - sp->radius_square;
	discri = half_b * half_b - a * c;
	if (discri < 0)
		return (FALSE);
	*root = (-half_b - sqrt(discri)) / a;
	if (*root < rec->tmin || *root > rec->tmax)
	{
		*root = (-half_b + sqrt(discri)) / a;
		if (*root < rec->tmin || *root > rec->tmax)
			return (FALSE);
	}
	return (TRUE);
}

double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_color	get_color_from_texture(t_img *img, double u, double v)
{
	int		x;
	int		y;
	int		offset;
	t_color	color;

	u = clamp(u, 0.0, 1.0);
	v = clamp(v, 0.0, 1.0);
	x = (int)(u * (img->width - 1));
	y = (int)(v * (img->height - 1));
	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
    if (offset < 0 || offset >= img->line_length * img->height)
		rt_error_handler("texture mapping", "invalid offset", 1);
	color.x = (*(unsigned char *)(img->addr + offset + 2)) / 255.0;
	color.y = (*(unsigned char *)(img->addr + offset + 1)) / 255.0;
	color.z = (*(unsigned char *)(img->addr + offset + 0)) / 255.0;
	return (color);
}

void	calculate_texture_coordinates(t_vec p, t_sphere *sp, double *u, double *v)
{
	double theta; // 위도
	double phi; // 경도

	theta = acos(clamp(p.y / sp->radius, -1.0, 1.0)); // 위도
	phi = atan2(p.z, p.x); // 경도
	*u = 1 - (phi + M_PI) / (2 * M_PI); // u 좌표
	*v = (theta) / M_PI; // v 좌표
}

void	texture_to_sphere(t_sphere *sp, t_img *img, t_hit_record *rec)
{
	t_vec	p;
	double	u;
	double	v;

	p = vec_minus_vec(rec->point, sp->center);
	// theta = acos(p.y / sp->radius);
	// phi = atan2(p.z, p.x);
	// u = 1 - (phi + M_PI) / (2 * M_PI);
	// v = (theta + M_PI / 2) / M_PI;
	calculate_texture_coordinates(p, sp, &u, &v);
	rec->reflect = get_color_from_texture(img, u, v);
}

double	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	double		root;
	t_sphere	*sp;

	sp = sp_obj->element;
	root = 0;
	if (get_discriminant(sp, &root, ray, rec) == FALSE)
		return (FALSE);
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->normal = vec_unit(vec_div(vec_minus_vec(rec->point, sp->center), sp->radius));
	set_face_normal(ray, rec);
	if (sp_obj->skin == e_img)
		texture_to_sphere(sp, sp_obj->img, rec);
	else
		rec->reflect = sp_obj->reflect;
	return (TRUE);
}

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	if (vec_inner_pro(ray->dir, rec->normal) < 0)
		rec->front_face = TRUE;
	else
		rec->front_face = FALSE;
	if (rec->front_face == FALSE)
		rec->normal = vec_mult_scal(rec->normal, -1);
}
