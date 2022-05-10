/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <hinterfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:21:24 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/25 16:45:33 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_object	cr_object(t_obj *data)
{
	t_vec *pos;
	t_vec *rot;

	pos = cr_point(data->c.x, data->c.y, data->c.z);
	rot = cr_point(data->v.x, data->v.y, data->v.z);
	if (data->type == 1)
		return (cr_sphere(pos, data->r, data->color, rot));
	else if (data->type == 2)
		return (cr_cyl(pos, data->r, data->color, rot));
	else if (data->type == 3)
		return (cr_cone(pos, data->r, data->color, rot));
	return (cr_plane(pos, rot, data->color));
}

int			count_light_len(t_list *light)
{
	int		res;

	res = 0;
	while (light)
	{
		light = light->next;
		res++;
	}
	return (res);
}

void		helper_fill(t_data data, t_mx *box, t_scene *scene, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		scene->light[j].pos = cr_point(((t_light *)(data.light->content))->x,
				((t_light *)(data.light->content))->y,
				((t_light *)(data.light->content))->z);
		scene->light[j].power = ((t_light *)(data.light->content))->intens;
		data.light = data.light->next;
		j++;
	}
	box->c_id = data.mlx.mlx;
	box->win_id = data.mlx.win;
	box->image_id = data.img.img;
	box->draw_arr = data.img.img_data;
	box->bits_per_pixel = data.canv.bit_per_pixel;
	box->size_line = data.canv.size_line;
	box->endian = data.canv.endline;
}

void		fill_middleware(t_scene *scene, t_data data, t_mx *box)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	scene->obj_count = data.obj_n;
	fill_z_buffer(scene);
	scene->objs = malloc(sizeof(t_object) * scene->obj_count);
	while (i < data.obj_n)
	{
		scene->objs[i] = cr_object((t_obj *)data.figur->content);
		data.figur = data.figur->next;
		i++;
	}
	scene->cam->dir = cr_point(data.camera.x, data.camera.y, data.camera.z);
	scene->cam->pos = cr_point(data.camera.canv_h,
	data.camera.canv_w, data.camera.canv_d);
	i = count_light_len(data.light);
	scene->light = malloc(sizeof(t_light) * i);
	scene->light_count = i;
	helper_fill(data, box, scene, i);
}

int			main(int argc, char **argv)
{
	t_data	data;
	t_scene	*scene;
	t_mx	*box;

	if (argc == 2)
	{
		if ((read_file(&data, argv[1])) == -1)
			return (0);
		if (!(box = malloc(sizeof(t_mx))))
			error_handler("memory error");
		if (!(scene = malloc(sizeof(t_scene))))
			error_handler("memory error");
		if (!(scene->cam = malloc(sizeof(t_cam))))
			error_handler("memory error");
		fill_middleware(scene, data, box);
		render(scene, box);
		mlx_put_image_to_window(box->c_id, box->win_id, box->image_id, 0, 0);
		free(scene->cam->dir);
		free(scene->cam->pos);
		mlx_hook(box->win_id, 17, 1L << 17, escape, &data);
		mlx_loop(box->c_id);
	}
	else
		error_output(USAGE);
	return (0);
}
