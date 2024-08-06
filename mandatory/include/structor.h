/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:47:57 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/04 21:07:59 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTOR_H
# define STRUCTOR_H

typedef int	t_bool;
# define FALSE 0
# define TRUE 1

typedef int	t_object_type;
# define SP 0
# define PL 1
# define CY 2
# define LIGHT_POINT 3
# define TRI 4
# define CONE 5

# define CONE_N 8

# define WIDTH 1920
# define HEIGHT 1080

# define EPSILON 1e-6
# define LUMEN 3

# define ORIGIN 0
# define CHANGE 1

# define FIRST 1
# define SECOND -1

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_matrix
{
	double	rix[3][3];
}	t_matrix;

typedef struct s_ray
{
	t_vec	orig;
	t_vec	dir;
}	t_ray;

typedef struct s_camera
{
	t_vec	orig;
	t_vec	ray_dir;
	double	viewport_h;
	double	viewport_w;
	t_vec	horizontal;
	t_vec	vertical;
	double	focal_len;
	t_vec	left_bottom;
	int		cam_num;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
}	t_vars;

typedef struct s_hit_record
{
	t_vec	point;
	t_vec	normal;
	double	tmin;
	double	tmax;
	double	t;
	t_bool	front_face;
	t_vec	reflect;
}	t_hit_record;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_sphere
{
	t_vec		center;
	double		radius;
	double		radius_square;
}	t_sphere;

typedef struct s_plane
{
	t_vec	plane_vec;
	double	constant;
	int		skin;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	c_vec;
	t_vec	center;
	double	height;
	double	radius;
}	t_cylinder;

typedef struct s_triangle
{
	t_vec	vertex0;
	t_vec	vertex1;
	t_vec	vertex2;
	t_vec	edge1;
	t_vec	edge2;
	t_vec	normal;
	t_vec	scale_vector;
	double	scale_factor;
	t_ray	*ray;
}	t_triangle;

typedef struct s_light
{
	t_vec	origin;
	t_vec	light_color;
	double	bright_ratio;
}	t_light;

typedef struct s_object
{
	t_object_type	type;
	t_object_type	skin;
	t_img			*img;
	t_img			*normal;
	void			*element;
	void			*next;
	t_vec			reflect;
}	t_object;

#endif