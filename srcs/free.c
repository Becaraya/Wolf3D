/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:51:13 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/24 15:08:25 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		free_tab_str(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(*str);
	free(str);
}

void		free_coo(t_coo *coo)
{
	if ((coo->next))
		free_coo(coo->next);
	if (coo)
		free(coo);
}

void		free_tab_int(int **tab, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
