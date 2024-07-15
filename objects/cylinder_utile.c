/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:03:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/15 19:21:49 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_ray	get_mid_ray(t_cylinder *cy, t_ray *ray)
{
	t_ray	t_ray;
	t_plane	*bottom;
	double	c_t;
	t_point	p1;
	t_point	p2;

	bottom = init_plane(cy->center, cy->c_vec);
	t_ray = ray_init(vec_plus_vec(ray->dir, ray->orig), \
					cy->c_vec);
	c_t = -1 * (vec_inner_pro(bottom->plane_vec, t_ray.orig) + bottom->constant) \
			/ (vec_inner_pro(t_ray.dir, bottom->plane_vec));
	p1 = ray_at(&t_ray, c_t);
	t_ray = ray_init(vec_plus_vec(vec_mult_scal(ray->dir, 2), ray->orig), cy->c_vec);
	c_t = -1 * (vec_inner_pro(bottom->plane_vec, t_ray.orig) + bottom->constant) \
			/ (vec_inner_pro(t_ray.dir, bottom->plane_vec));
	p2 = ray_at(&t_ray, c_t);
	free(bottom);
	return (ray_init(p2, vec_minus_vec(p1, p2)));
}

int	discriment_cy(t_ray bot_ray, t_cylinder *cy, double *root)
{
	double		a;
	double		half_b;
	double		c;
	double		discri;

	a = vec_len_square(bot_ray.dir);
	half_b = vec_inner_pro(bot_ray.dir, \
	vec_minus_vec(bot_ray.orig, cy->center));
	c = vec_len_square(cy->center) + vec_len_square(bot_ray.orig) - \
	(cy->radius * cy->radius) - (2 * vec_inner_pro(cy->center, bot_ray.orig));
	discri = half_b * half_b - a * c;
	if (discri < 0)
		return (FALSE);
	root[0] = (-half_b - sqrt(discri)) / a;
	root[1] = (-half_b + sqrt(discri)) / a;
	return (TRUE);
}

int	check_in_height(t_hit_record *rec, t_cylinder *cy, t_ray *ray)
{
	t_plane	*pl;
	t_point	hit_middle;
	double	t;
	t_ray	center_ray;

	pl = init_plane(rec->point, cy->c_vec);
	center_ray = ray_init(cy->center, cy->c_vec);
	t = -1 * (vec_inner_pro(pl->plane_vec, center_ray.orig) + pl->constant) \
			/ vec_inner_pro(pl->plane_vec, center_ray.dir);
	free(pl);
	hit_middle = vec_plus_vec(cy->center, vec_mult_scal(cy->c_vec, t));
	if (point_to_point(hit_middle, cy->center) >= cy->height / 2)
		return (FALSE);
	rec->normal = vec_unit(vec_minus_vec(rec->point, hit_middle));
	set_face_normal(ray, rec);
	return (TRUE);
}

int	get_t(t_cylinder *cy, t_ray *ray, t_hit_record *rec, double *t)
{
	t_ray	mid_ray;
	double	*root;
	t_ray	vertical;

	root = ft_calloc(2, sizeof(int));
	mid_ray = get_mid_ray(cy, ray);
	if (discriment_cy(mid_ray, cy, root) == FALSE)
	{
		free(root);
		return (FALSE);
	}
	vertical = ray_init(ray_at(&mid_ray, root[1]), cy->c_vec);
	*t = get_meet_point(vertical, ray);
	if (*t < rec->tmin || *t > rec->tmax)
	{
		vertical = ray_init(ray_at(&mid_ray, root[0]), cy->c_vec);
		free(root);
		*t = get_meet_point(vertical, ray);
		if (*t < rec->tmin || *t > rec->tmax)
			return (FALSE);
	}
	return (TRUE);
}

double	get_meet_point(t_ray v_ray, t_ray *ray)
{
	double	t;

	t = (v_ray.dir.x * (ray->orig.y - v_ray.orig.y) - v_ray.dir.y * (ray->orig.x - v_ray.orig.x)) / \
	//t = ((v_ray.dir.y * v_ray.orig.x) - (v_ray.dir.x * v_ray.orig.y)) / 
		((v_ray.dir.y * ray->dir.x) - (ray->dir.y * v_ray.dir.x));
	return (t);
}
