/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:51:41 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/31 15:52:17 by becaraya         ###   ########.fr       */
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

void	print_map(t_all *al) // a suppr
{
	int i;
	int j;
	t_coo *coo_h;

	i = 0;
	j = 0;
	coo_h = al->coo;
	while (i < al->y_mx_map)
	{
		while (j < al->x_mx_map)
		{
			ft_putnbr(al->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		putchar('\n');
		j = 0;
		i++;
	}
}
