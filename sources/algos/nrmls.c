/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nrmls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:10:02 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/23 21:10:07 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_vec	*find_cone_n(t_vec *point, t_scene *scene, t_vec *sender)
{
	t_vec *res;
	t_vec *a;
	t_vec *b;
	t_vec *n_cyl;

	a = ft_substr(point, (scene->objs[(int)sender->i].p1));
	n_cyl = find_n_cyl(sender->j, point, scene, sender->i);
	b = ft_substr(a, n_cyl);
	ft_vec_mult(b, (1 + CON_ANG * CON_ANG));
	res = ft_substr(a, b);
	free(a);
	free(b);
	free(n_cyl);
	return (res);
}

float	sp_find_b(t_vec *point, t_vec *p1, t_vec *dir)
{
	float		res;
	t_vec		*a;

	a = ft_substr(point, p1);
	res = 2 * ft_scal(dir, a);
	free(a);
	return (res);
}

float	sp_find_c(t_vec *point, t_vec *p1, float radius)
{
	float		res;
	t_vec		*a;
	t_vec		*b;

	a = ft_substr(point, p1);
	b = ft_substr(point, p1);
	res = ft_scal(a, b) - radius * radius;
	free(a);
	free(b);
	return (res);
}

t_vec	*find_n_cyl(float t, t_vec *point, t_scene *scene, int index)
{
	t_vec		*res;
	t_vec		*obj;
	t_vec		*va;
	t_vec		*po;
	float		k;

	obj = (scene->objs[index].p1);
	va = scene->objs[index].rot;
	k = (ft_scal(va, point) - ft_scal(va, obj)) / (ft_scal(va, va));
	po = cr_point(obj->i + k * va->i, obj->j + k * va->j, obj->k + k * va->k);
	res = ft_substr(po, point);
	free(po);
	t += 0;
	return (res);
}
