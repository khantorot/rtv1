/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:09:06 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/23 21:09:09 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

float	find_cos(t_vec *vec1, t_vec *vec2)
{
	return (ft_scal(vec1, vec2) / (ft_vec_len(vec1) * ft_vec_len(vec2)));
}

float	ft_vec_len(t_vec *vec)
{
	return (sqrt(vec->i * vec->i + vec->j * vec->j + vec->k * vec->k));
}

void	ft_normilize(t_vec *vec)
{
	float len;

	len = ft_vec_len(vec);
	vec->i /= len;
	vec->j /= len;
	vec->k /= len;
}

t_vec	*ft_vec_mult(t_vec *vec, float mult)
{
	vec->i *= mult;
	vec->j *= mult;
	vec->k *= mult;
	return (vec);
}

t_vec	*ftm_vec_mult(t_vec *vec, float mult)
{
	t_vec *test;

	if (!(test = malloc(sizeof(t_vec))))
		error_handler("memory error");
	test->i = vec->i * mult;
	test->j = vec->j * mult;
	test->k = vec->k * mult;
	return (test);
}
