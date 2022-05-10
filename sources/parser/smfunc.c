/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinterfa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:06:46 by hinterfa          #+#    #+#             */
/*   Updated: 2020/11/23 21:06:54 by hinterfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int		len_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}
