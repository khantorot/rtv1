/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <hinterfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:12:02 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/25 16:51:10 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_vec		*cr_point(float i, float j, float k)
{
	t_vec		*ball;

	if (!(ball = malloc(sizeof(t_vec))))
		error_handler("memory error");
	ball->i = i;
	ball->j = j;
	ball->k = k;
	return (ball);
}

t_object	cr_sphere(t_vec *p1, float radius, unsigned int color, t_vec *p4)
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
	res.col = cr_point(0, 0, 0);
	res.radius = radius;
	res.color = color;
	res.ray_intersect = ray_intersect_sp;
	res.color_find = color_find_sp;
	free(init_vec);
	free(p4);
	return (res);
}

double		get_t(float a, float b, float d)
{
	double		t1;
	double		t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0) || (t1 >= 0 && t2 < 0))
		return (t1);
	if ((t2 <= t1 && t2 >= 0) || (t2 >= 0 && t1 < 0))
		return (t2);
	return (-1);
}

float		ray_intersect_sp(t_vec *dir, t_vec *point, t_object object)
{
	float		a;
	float		b;
	float		c;
	float		d;
	float		t;

	a = ft_scal(dir, dir);
	b = sp_find_b(point, object.p1, dir);
	c = sp_find_c(point, object.p1, object.radius);
	d = b * b - 4 * a * c;
	t = d < 0 ? -1 : get_t(a, b, d);
	if (t < 0)
		return (0);
	return (t);
}

t_vec		*color_find_sp(t_vec *point, t_scene *scene, t_vec *sender, int k)
{
	t_vec		*n;
	t_vec		*vec2;
	t_vec		*vec1;
	t_vec		*res;
	t_vec		*h;

	res = malloc(sizeof(t_vec));
	n = ft_substr(scene->objs[(int)sender->i].p1, point);
	vec2 = ft_substr(point, scene->light[k].pos);
	vec1 = ft_substr(point, scene->cam->pos);
	ft_normilize(n);
	ft_normilize(vec1);
	ft_normilize(vec2);
	res->i = ft_scal(n, vec2);
	h = ft_add_vec(vec2, vec1);
	ft_normilize(h);
	res->j = ft_scal(h, n);
	free(n);
	free(vec2);
	free(h);
	free(vec1);
	return (res);
}
