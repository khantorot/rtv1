/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <hinterfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:13:11 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/25 18:06:29 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	render(t_scene *scene, t_mx *box)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	scene->cam->pos->i += 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			helper_for_render(i, j, scene, box);
			i++;
		}
		i = 0;
		j++;
	}
}

void	helper_for_render(int i, int j, t_scene *scene, t_mx *box)
{
	t_vec	*greed_point;
	t_vec	*cam;
	t_vec	*dir;
	float	angle;

	angle = tan(M_PI * 0.5 * FOV / 180.);
	cam = cr_point(0, 0, 0);
	greed_point = cr_point(((float)2 * (i - 1 / 2) / WIDTH - 1),
	((float)2 * (j - 1 / 2) / WIDTH - 1), 1);
	greed_point->i = (2 * ((i + 0.5) / WIDTH) - 1) * angle * WIDTH / HEIGHT;
	greed_point->j = (1 - 2 * ((j + 0.5) / HEIGHT)) * angle;
	greed_point->k = 1;
	dir = ft_substr(greed_point, cam);
	ft_normilize(dir);
	*dir = vec_rot(*dir, *(scene->cam->dir));
	ft_normilize(dir);
	*(int *)(box->draw_arr + (i + j * WIDTH) * (box->bits_per_pixel / 8)) =
	cast_ray(dir, scene, j * WIDTH + i);
	free(greed_point);
	free(cam);
	free(dir);
}

float	cast_ray(t_vec *dir, t_scene *sc, unsigned int index)
{
	float	t;
	int		i;
	int		res;
	t_vec	*sender;

	i = 0;
	res = 0x000000;
	if (!(sender = malloc(sizeof(t_vec))))
		error_handler("memory error");
	while (i < sc->obj_count)
	{
		if ((t = sc->objs[i].ray_intersect(dir, sc->cam->pos, sc->objs[i])))
		{
			if ((t -= 0.001) <= sc->z_buffer[index])
			{
				sc->z_buffer[index] = t;
				sender->j = t;
				sender->i = i;
				res = norm_fixer2(sender, sc, dir, index);
			}
		}
		i++;
	}
	free(sender);
	return (res);
}

t_vec	*help_cast(t_vec *snd, t_scene *scene, t_vec *dir, unsigned int index)
{
	int		k;
	t_vec	*point;
	float	distance;
	t_vec	*res;
	t_vec	*input;

	index += 0;
	if (!(res = malloc(sizeof(t_vec))))
		error_handler("memory error");
	point = point_coords(scene, snd->j, dir);
	res->i = 0;
	res->j = 0;
	k = 0;
	while (k < scene->light_count)
	{
		distance = calc_dist(scene->light[k].pos, point);
		if (path_clear(point, scene, snd->i, k))
		{
			input = scene->objs[(int)snd->i].color_find(point, scene, snd, k);
			norm_fixer1(res, input, distance, scene->light[k].power);
		}
		k++;
	}
	free(point);
	return (res);
}

int		path_clear(t_vec *point, t_scene *scene, int i, int k)
{
	t_vec	*newdir;
	int		j;
	int		res;

	j = 0;
	res = 0;
	newdir = ft_substr(scene->light[k].pos, point);
	ft_normilize(newdir);
	while (j < scene->obj_count)
	{
		if (j != i)
		{
			i += 0;
			if (scene->objs[j].ray_intersect(newdir, point, scene->objs[j])
				&& scene->objs[j].col->i != 1)
			{
				free(newdir);
				return (0);
			}
		}
		j++;
	}
	free(newdir);
	return (1);
}
