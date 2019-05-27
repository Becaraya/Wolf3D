/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:51:41 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/27 10:35:34 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			len_tn(char **tmp)
{
	int		count;

	count = 0;
	while(tmp[count])
		count++;
	return (count);
}

int			*intsub(t_all *al, int i, int j)
{
	int		count;
	int		*result;

	count = 0;
	result = NULL;
	if (!(result = (int **)malloc(sizeof(int *) * al->x_mx_map)))
		return (EXIT_FAILURE);
	ft_bzero(result, sizeof(int));
	return (EXIT_SUCCESS);
}

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
