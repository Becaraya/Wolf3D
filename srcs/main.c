/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:05 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/31 11:45:02 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	t_all	al;
	int		fd;

	fd = 0;
	ft_bzero(&al, sizeof(t_all));
	if (argc == 2)
	{
		if (!(al.coo = (t_coo *)malloc(sizeof(t_coo))))
			return (EXIT_FAILURE);
		al.coo->x = -1;
		al.coo->y = -1;
		al.coo->z = -1;
		pars(&al, argv[1], fd);
		print_map(&al);
	}
	return (0);
}
