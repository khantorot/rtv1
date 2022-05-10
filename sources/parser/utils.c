/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <hinterfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 23:20:53 by glychest          #+#    #+#             */
/*   Updated: 2020/11/23 22:01:16 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	check_tab_len(char **tab)
{
	if (len_tab(tab) != 2)
	{
		free_tab(tab);
		error_output(INVALID);
		exit(-1);
	}
}

int		help_strtodbl(char *s)
{
	int dot;
	int i;

	i = 0;
	dot = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
			dot++;
		i++;
	}
	return (dot);
}

double	ft_strtodbl(char *s)
{
	char		**tab;
	t_vector	n;
	int			len;
	int			dot;

	n.x = 0.0;
	n.y = 0;
	dot = help_strtodbl(s);
	if (!dot)
		return ((double)ft_atoi(s));
	tab = ft_strsplit(s, '.');
	check_tab_len(tab);
	n.x = (double)ft_atoi(tab[0]);
	n.y = (double)ft_atoi(tab[1]);
	len = ft_strlen(tab[1]);
	while (--len > -1)
		n.y /= 10;
	n.x += n.y;
	free_tab(tab);
	return (n.x);
}

int		find_type(char *type)
{
	int t;

	t = 0;
	if (ft_strequ(type, "sphere"))
		t = SPHERE;
	else if (ft_strequ(type, "cone"))
		t = CONE;
	else if (ft_strequ(type, "cylinder"))
		t = CYLINDER;
	else if (ft_strequ(type, "plane"))
		t = PLANE;
	return (t);
}

double	convert_to_rad(double a)
{
	while (a > 360.0)
		a -= 360.0;
	while (a < 0.0)
		a += 360.0;
	a = (a * PI) / 360.0;
	return (a);
}
