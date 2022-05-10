/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <hinterfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:09:21 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/25 17:29:22 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		error_handler(char *error)
{
	ft_putendl(error);
	exit(1);
	return (1);
}

void	norm_fixer1(t_vec *res, t_vec *input, float distance, float power)
{
	res->i += input->i * power
	/ (distance * distance);
	res->j += pow(input->j, 80);
	free(input);
}

int		norm_fixer2(t_vec *sender, t_scene *scene, t_vec *dir, unsigned int ind)
{
	t_vec	*values;
	int		res;

	values = help_cast(sender, scene, dir, ind);
	res = ft_calc_res(scene, sender->i, values->i, values->j);
	free(values);
	return (res);
}

float	calc_dist(t_vec *pos_light, t_vec *point)
{
	float res;
	t_vec *a;

	a = ft_substr(pos_light, point);
	res = ft_vec_len(a);
	free(a);
	return (res);
}

void	fill_z_buffer(t_scene *scene)
{
	int		i;

	i = 0;
	scene->z_buffer = malloc(WIDTH * HEIGHT * sizeof(float));
	while (i < WIDTH * HEIGHT)
		scene->z_buffer[i++] = MAXDIST;
}
