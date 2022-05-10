/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:07:33 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/23 21:07:36 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_col(float offset, unsigned int color)
{
	int		red;
	int		green;
	int		blue;
	int		c1;
	int		c2;

	c2 = color;
	c1 = 0x000000;
	red = get_light((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, offset);
	green = get_light((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, offset);
	blue = get_light(c1 & 0xFF, c2 & 0xFF, offset);
	return ((red << 16) | (green << 8) | blue);
}

void	ft_add_spec(t_vec *diffuse, float spec, float ndotl)
{
	spec = saturate(spec);
	diffuse->i += 255 * spec * ndotl;
	diffuse->j += 255 * spec * ndotl;
	diffuse->k += 255 * spec * ndotl;
}

int		ft_calc_res(t_scene *scene, int i, float ndotl, float spec)
{
	t_vec	*diffuse;
	int		res;

	ndotl = saturate(ndotl);
	res = get_col(ndotl, scene->objs[i].color);
	diffuse = ft_split_col(res);
	ft_add_spec(diffuse, spec, ndotl);
	res = ft_icol(diffuse);
	free(diffuse);
	return (res);
}

float	saturate(float d)
{
	if (d < 0)
		return (0);
	if (d > 1)
		return (1);
	return (d);
}
