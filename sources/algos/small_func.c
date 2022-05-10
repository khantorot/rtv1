/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:12:18 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/23 21:12:21 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_vec	*point_coords(t_scene *scene, float t, t_vec *dir)
{
	t_vec *point;

	if (!(point = malloc(sizeof(t_vec))))
		error_handler("memory error");
	point->i = scene->cam->pos->i + t * dir->i;
	point->j = scene->cam->pos->j + t * dir->j;
	point->k = scene->cam->pos->k + t * dir->k;
	return (point);
}

int		ft_icol(t_vec *col)
{
	col->i = col->i < 255 ? col->i : 255;
	col->j = col->j < 255 ? col->j : 255;
	col->k = col->k < 255 ? col->k : 255;
	return (((int)col->i << 16) + ((int)col->j << 8) + (int)col->k);
}

t_vec	*ft_split_col(int color)
{
	t_vec *res;

	if (!(res = malloc(sizeof(t_vec))))
		error_handler("memory error");
	res->i = color >> 16 & 0xFF;
	res->j = color >> 8 & 0xFF;
	res->k = color & 0xFF;
	return (res);
}

void	memorer(t_scene *scene, t_mx *box)
{
	if (!(box = malloc(sizeof(t_mx))))
		error_handler("memory error");
	if (!(scene = malloc(sizeof(t_scene))))
		error_handler("memory error");
	if (!(scene->cam = malloc(sizeof(t_cam))))
		error_handler("memory error");
}
