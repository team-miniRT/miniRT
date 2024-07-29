/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:47:57 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/29 21:59:32 by yeoshin          ###   ########.fr       */
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

# define CONE_N 160

# define WIDTH 1920
# define HEIGHT 1080

# define EPSILON 1e-6
# define LUMEN 3

# define FIRST 1
# define SECOND -1

//enum {
//	FIRST,
//	SECOND
//};

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_vec	t_point;
typedef struct s_vec	t_color;
typedef struct s_light	t_light;

typedef struct s_ray
{
	t_point	orig;
	t_vec	dir;
}	t_ray;

typedef struct s_camera
{
	t_point	orig;
	t_vec	ray_dir;
	double	viewport_h;
	double	viewport_w;
	t_vec	horizontal;
	t_vec	vertical;
	double	focal_len;
	t_point	left_bottom;
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
	t_point	point;
	t_vec	normal;
	double	tmin;
	double	tmax;
	double	t;
	t_bool	front_face;
	t_color	reflect;
}	t_hit_record;

typedef struct s_skin
{
	t_vars	*img;
	int		x;
	int		y;
	int		x_len;
	int		y_len;
}	t_skin;

typedef struct s_sphere
{
	//t_skin		skin;
	t_point		center;
	double		radius;
	double		radius_square;
	int			x;
	int			y;
}	t_sphere;

//typedef struct s_line
//{
//	t_point	l_point;
//	t_vec	l_vec;
//}	t_line;

typedef struct s_plane
{
	t_vec	plane_vec;
	double	constant;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	c_vec;
	t_point	center;
	double	height;
	double	radius;
}	t_cylinder;

typedef struct s_triangle
{
	t_point	vertex0;
	t_point	vertex1;
	t_point	vertex2;
	t_vec	edge1;
	t_vec	edge2;
	t_vec	normal;
	t_vec	scale_vector;
	double	scale_factor;
	t_ray	*ray;
}	t_triangle;

typedef struct s_light
{
	t_point	origin;
	t_color	light_color;
	double	bright_ratio;
}	t_light;

typedef struct s_object
{
	t_object_type	type;
	void			*img[10];
	void			*element;
	void			*next;
	t_color			reflect;
}	t_object;

#endif