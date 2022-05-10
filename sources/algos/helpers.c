/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:08:53 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/23 21:08:55 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_vec	*ft_substr(t_vec *vec1, t_vec *vec2)
{
	t_vec *nw;

	if (!(nw = malloc(sizeof(t_vec))))
		error_handler("memory error");
	nw->i = vec1->i - vec2->i;
	nw->j = vec1->j - vec2->j;
	nw->k = vec1->k - vec2->k;
	return (nw);
}

t_vec	*ft_add_vec(t_vec *vec1, t_vec *vec2)
{
	t_vec *nw;

	if (!(nw = malloc(sizeof(t_vec))))
		error_handler("memory error");
	nw->i = vec1->i + vec2->i;
	nw->j = vec1->j + vec2->j;
	nw->k = vec1->k + vec2->k;
	return (nw);
}

t_vec	*ftm_add_vec(t_vec *vec1, t_vec *vec2)
{
	t_vec *nw;

	if (!(nw = malloc(sizeof(t_vec))))
		error_handler("memory error");
	nw->i = vec1->i + vec2->i;
	nw->j = vec1->j + vec2->j;
	nw->k = vec1->k + vec2->k;
	return (nw);
}

float	ft_scal(t_vec *vec1, t_vec *vec2)
{
	return (vec1->i * vec2->i + vec1->j * vec2->j + vec1->k * vec2->k);
}

void	check_dir(t_vec *dir)
{
	float res;

	res = sqrt(dir->i * dir->i + dir->j * dir->j + dir->k * dir->k);
}
