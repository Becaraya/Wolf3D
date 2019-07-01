/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:51:41 by becaraya          #+#    #+#             */
/*   Updated: 2019/07/01 07:54:41 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_add_coo(t_all *al, int x, int y, int z)
{
	t_coo	*new;

	if (al->coo->x == -1 && al->coo->y == -1 && al->coo->z == -1)
	{
		al->coo->x = x;
		al->coo->y = y;
		al->coo->z = z;
	}
	else
	{
		if (!(new = (t_coo *)malloc(sizeof(t_coo))))
			return (EXIT_FAILURE);
		new->next = NULL;
		new->x = x;
		new->y = y;
		new->z = z;
		al->coo->next = new;
		al->coo = new;
	}
	return (EXIT_SUCCESS);
}

int			ft_is_valid_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int			verif_n_free(t_all *al)
{
	int i;

	i = 0;
	while (i < al->x_mx_map)
	{
		if (al->map[0][i] == 0 || al->map[al->y_mx_map - 1][i] == 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < al->y_mx_map)
	{
		if (al->map[i][0] == 0 || al->map[i][al->x_mx_map - 1] == 0)
			return (EXIT_FAILURE);
		i++;
	}
	free_coo(al->coo);
	return (EXIT_SUCCESS);
}
