/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:51:41 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/28 12:54:49 by becaraya         ###   ########.fr       */
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

int			ft_is_valid_tab(char **str, t_all *al)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while(str[i])
	{
		if (!(ft_is_valid_str(str[i])))
			return (0);
		i++;
	}
	if (al->y_mx_map == 0)
		al->x_mx_map = i;
	else
	{
		j = i;
		if (j != al->x_mx_map)
			return (0);
	}
	return (1);
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
	while (i <= al->y_mx_map)
	{
		while (y < al->x_mx_map)
		{
			ft_putnbr(al->map[i][y]);
			ft_putchar(' ');
			y++;
		}
		putchar('\n');
		y = 0;
		i++;
	}
}
