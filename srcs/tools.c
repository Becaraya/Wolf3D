/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:51:41 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/31 11:43:48 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_free_tab(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(*str);
	str = NULL;
}

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

void	print_map(t_all *al)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (al->coo)
	{
		if (al->coo->x == 0)
			ft_putchar('\n');
		ft_putnbr(al->coo->z);
		ft_putchar(' ');
		al->coo = al->coo->next;
	}
}
