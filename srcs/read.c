/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:13:45 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/27 10:36:26 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


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

int		mouv_line(char **tmp, t_all *al, int y)
{
	int i;

	i = 0;
	if (!(al->map[y] = (int *)malloc(sizeof(int) * al->x_mx_map)))
		return (EXIT_FAILURE);
	while (i < al->x_mx_map)
	{
		al[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int		realloc_tab(char **tmp, t_all *al, int y)
{
	int		i;
	int		j;
	int		**tab_int_tmp;

	i = 0;
	j = 0;
	if ((!(tab_int_tmp = (int **)malloc(sizeof(int *)))))
		return (EXIT_FAILURE);
	while (i < y)
	{
		if ((!(tab_int_tmp[i] = (int *)malloc(sizeof(int) * al->x_mx_map))))
			return (EXIT_FAILURE);
		while (j < al->x_mx_map)
		{
			tab_int_tmp[i][j] = al->map[i][j];
			j++;
		}
		j = 0;
		ft_bzero(al->map[i], al->x_mx_map);
		i++;
	}
	if ((!(al->map = (int **)malloc(sizeof(int*) * y + 1))))
		return (EXIT_FAILURE);
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < al->x_mx_map)
		{
			al->map[i][j] = tab_int_tmp[i][j];
			j++;
		}
		j = 0;
		free(tab[i]);
		i++;
	}
	free(tab);
	if (mouv_line(tmp, all, y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		first_line(t_all *al, int len_lgn)
{
	if ((!(al->map = (int **)malloc(sizeof(int *)))))
		return (EXIT_FAILURE);
	al->x_mx_map = len_lgn;
	return (EXIT_SUCCESS);
}

int		read_line(char *line, t_all *al, int y)
{
	int		len_lgn;
	char	**tmp;

	if ((tmp = ft_strsplit(str, ' ')) == NULL || ((len_lgn = len_tb(tmp)) == 0))
		return (EXIT_FAILURE);
	if (al->x_mx_map == 0 && (first_line(al, len_lgn) == EXIT_FAILURE))
	{
		ft_free_tab(tmp);
		free(tmp);
		return (EXIT_FAILURE);
	}
	if ((y == 0 && mouv_line(tmp, al, 0, len_lgn) == EXIT_FAILURE)
		|| (y != 0 && realloc_tab(tmp, al, y) == EXIT_FAILURE))
	{
		//fct_free(le tableau d int deja malloc)
		ft_free_tab(tmp);
		free(tmp);
		return (EXIT_FAILURE);
	}
	ft_free_tab(tmp);
	free(tmp);
	return (EXIT_SUCCESS);
}

int		do_gnl(t_all *al, char *map)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	fd = 0;
	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((error = get_next_line(fd, &line)) > 0)
	{
		if (read_line(line, map, y++) == EXIT_FAILURE)
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

int		pars(t_all *al, char *map)
{
	int y;

	if (do_gnl(al, map) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
