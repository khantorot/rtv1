/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <hinterfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:08:27 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/25 16:50:18 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_object	cr_cyl(t_vec *p1, float radius, unsigned int color, t_vec *p4)
{
	t_object	res;
	t_vec		*angletovec;
	t_vec		*init_vec;

	if (!(angletovec = malloc(sizeof(t_vec))))
		error_handler("memory error");
	init_vec = cr_point(0, 1, 0);
	res.p1 = p1;
	*angletovec = vec_rot(*init_vec, *p4);
	res.rot = angletovec;
	res.radius = radius;
	res.col = cr_point(0, 0, 0);
	res.color = color;
	res.ray_intersect = ray_intersect_cylinder;
	res.color_find = col_cyl;
	free(init_vec);
	free(p4);
	return (res);
}

float		find_b_cyl(t_vec *point, t_vec *p1, t_vec *rot, t_vec *dir)
{
	float	res;
	t_vec	*to_del;

	to_del = ft_substr(point, p1);
	res = 2 * (ft_scal(dir, to_del) - ft_scal(dir, rot) * ft_scal(to_del, rot));
	free(to_del);
	return (res);
}

float		find_c_cyl(t_vec *point, t_vec *p1, t_vec *rot, float radius)
{
	float	res;
	t_vec	*to_del;

	to_del = ft_substr(point, p1);
	res = ft_scal(to_del, to_del) - ft_scal(to_del, rot)
	* ft_scal(to_del, rot) - radius * radius;
	free(to_del);
	return (res);
}

float		ray_intersect_cylinder(t_vec *dir, t_vec *point, t_object obj)
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	t;

	a = ft_scal(dir, dir) - ft_scal(dir, obj.rot)
	* ft_scal(dir, obj.rot);
	b = find_b_cyl(point, obj.p1, obj.rot, dir);
	c = find_c_cyl(point, obj.p1, obj.rot, obj.radius);
	d = b * b - 4 * a * c;
	t = d < 0 ? -1 : get_t(a, b, d);
	if (t < 0)
		return (0);
	return (t);
}

t_vec		*col_cyl(t_vec *point, t_scene *scene, t_vec *sender, int k)
{
	t_vec	*n;
	t_vec	*res;
	t_vec	*vec1;
	t_vec	*vec2;
	t_vec	*h;

	if (!(res = malloc(sizeof(t_vec))))
		error_handler("memory error");
	vec2 = ft_substr(point, scene->light[k].pos);
	vec1 = ft_substr(point, scene->cam->pos);
	n = find_n_cyl(sender->j, point, scene, sender->i);
	ft_normilize(n);
	ft_normilize(vec2);
	res->i = ft_scal(n, vec2);
	h = ft_add_vec(vec2, vec1);
	ft_normilize(h);
	res->j = ft_scal(h, n);
	free(vec1);
	free(vec2);
	free(n);
	free(h);
	return (res);
}
