/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 23:44:25 by glychest          #+#    #+#             */
/*   Updated: 2020/11/19 19:36:33 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_light		*new_light(t_light l)
{
	t_light	*light;

	light = (t_light*)malloc(sizeof(t_light));
	light->x = l.x;
	light->y = l.y;
	light->z = l.z;
	light->intens = l.intens;
	return (light);
}

t_light		init_light(double x, double y, double z, double intens)
{
	t_light	light;

	light.x = x;
	light.y = y;
	light.z = z;
	light.intens = intens;
	return (light);
}

void		init_lights(t_data *p, char **s)
{
	t_light	l;
	t_light	*new_l;

	l = init_light(ft_strtodbl(s[0]), ft_strtodbl(s[1]),
			ft_strtodbl(s[2]), ft_strtodbl(s[3]));
	new_l = new_light(l);
	ft_lstadd(&p->light, ft_lstnew(new_l, sizeof(t_light)));
	free(new_l);
}

int			set_light(t_data *p, char **tab)
{
	char	**str;

	str = ft_strsplit(tab[2], ',');
	if (len_tab(str) < 4)
	{
		free_tab(str);
		error_output(PARAMETERS);
		exit(0);
	}
	if (ft_strequ(tab[0], "light") && ft_strequ(tab[1], "point"))
		init_lights(p, str);
	free_tab(str);
	return (0);
}
