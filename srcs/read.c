/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:13:45 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/03 09:29:18 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			list_to_tab(t_all *al)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(al->map = (int **)malloc(sizeof(int *) * al->y_mx_map)))
		return (EXIT_FAILURE);
	while (j < al->y_mx_map)
	{
		if (!(al->map[j] = (int *)malloc(sizeof(int) * al->x_mx_map)))
		{
			free_tab_int(al->map, j);
			return (EXIT_FAILURE);
		}
		while (i < al->x_mx_map)
		{
			al->map[j][i] = al->coo->z;
			al->coo = al->coo->next;
			i++;
		}
		i = 0;
		j++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_add_l(char **str, t_all *al, int *x, int y)
{
	int		i;
	char	**tmp;

	i = 0;
	if ((tmp = ft_strsplit(*str, ' ')) == NULL)
		return (EXIT_FAILURE);
	while (tmp[i])
	{
		if (ft_is_valid_str(tmp[i]) == 0
			|| ft_add_coo((al), i, y, ft_atoi(tmp[i])) == EXIT_FAILURE)
		{
			free_tab_str(tmp);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (*x == 0)
		*x = i;
	else if (*x != i)
		i = 0;
	free_tab_str(tmp);
	return ((i == 0) ? EXIT_FAILURE : EXIT_SUCCESS);
}

static int	do_gnl(int fd, t_all *al, char *str, int error)
{
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((error = get_next_line(fd, &line)) > 0)
	{
		if (ft_add_l(&line, al, &al->x_mx_map, y++) == EXIT_FAILURE)
		{
			ft_strdel(&line);
			close(fd);
			return (-1);
		}
		ft_strdel(&line);
	}
	close(fd);
	return (y);
}

int			pars(t_all *al, char *str, int fd)
{
	int		y;
	int		error;
	t_coo	*map_h;

	error = 0;
	map_h = al->coo;
	al->x_mx_map = 0;
	y = do_gnl(fd, al, str, error);
	al->coo = map_h;
	if (error == -1 || y < 1 || (y == 1 && al->x_mx_map == 1))
		return (EXIT_FAILURE);
	if ((al->y_mx_map = y) != 0)
	{
		al->coo = map_h;
		while (al->coo)
			al->coo = al->coo->next;
		al->coo = map_h;
	}
	else
		al->coo = NULL;
	return ((al->y_mx_map > 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}

int			read_n_pars(t_all *al, char *argv)
{
	int		fd;
	t_coo	*coo_h;

	fd = 0;
	coo_h = NULL;
	if (!(al->coo = (t_coo *)malloc(sizeof(t_coo))))
		return (EXIT_FAILURE);
	al->coo->x = -1;
	al->coo->y = -1;
	al->coo->z = -1;
	coo_h = al->coo;
	if (pars(al, argv, fd) == EXIT_FAILURE)
	{
		free(al->coo);
		return (EXIT_FAILURE);
	}
	if (list_to_tab(al) == EXIT_FAILURE)
	{
		free_coo(al->coo);
		free(al->coo);
		return (EXIT_FAILURE);
	}
	al->coo = coo_h;
	return (EXIT_SUCCESS);
}
