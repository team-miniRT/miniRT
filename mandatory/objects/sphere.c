/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:14:02 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/08 14:57:25 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere	*init_sphere(t_vec center, double radius)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	if (sp == NULL)
		exit(1);
	sp->center = center;
	sp->radius = radius;
	sp->radius_square = radius * radius;
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

void	calculate_texture_coordinates(t_vec p, t_sphere *sp, \
										double *u, double *v)
{
	double	theta;
	double	phi;

	theta = acos(clamp(p.y / sp->radius, -1.0, 1.0));
	phi = atan2(p.z, p.x);
	*u = 1 - (phi + M_PI) / (2 * M_PI);
	*v = (theta) / M_PI;
}

void	texture_to_sphere(t_sphere *sp, t_object *sp_obj, t_hit_record *rec)
{
	t_vec	p;
	double	u;
	double	v;
	t_vec	normal;

	p = vec_minus_vec(rec->point, sp->center);
	calculate_texture_coordinates(p, sp, &u, &v);
	rec->reflect = get_color_from_texture(sp_obj->img, u, v);
	normal = get_color_from_texture(sp_obj->normal, u, v);
	normal = vec_plus_scal(vec_mult_scal(normal, -2), 1, 1, 1);
	rec->normal = vec_div(vec_plus_vec(normal, rec->normal), 2);
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
	rec->normal = vec_unit(vec_div(vec_minus_vec(rec->point, sp->center), \
							sp->radius));
	set_face_normal(ray, rec);
	rec->reflect = sp_obj->reflect;
	if (sp_obj->skin == e_img)
		texture_to_sphere(sp, sp_obj, rec);
	else if (sp_obj->skin == e_check)
	{
		if (checker_point(rec->point, sp))
			rec->reflect = reverse_color(sp_obj->reflect);
	}
	return (TRUE);
}
