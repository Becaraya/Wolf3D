/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:13:45 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/28 13:06:01 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mouv_line(t_all *al, char **tmp, int y)
{
	int		j;

	j = 0;
	if (!(al->map[y] = (int *)malloc(sizeof(int) * al->x_mx_map)))
		return (EXIT_FAILURE);
	ft_bzero(al->map[y], sizeof(int) * al->x_mx_map);
	while (j < al->x_mx_map)
	{
		al->map[y][j] = ft_atoi(tmp[j]);
		j++;
	}
	return (EXIT_SUCCESS);
}

int		mouv_tab(t_all *al, char **tmp, int **tmp_int)
{
	int		i;

	i = 0;
	if (!(tmp_int = (int **)malloc(sizeof(int *) * al->y_mx_map + 1)))
		return (EXIT_FAILURE);
	ft_bzero(tmp_int, sizeof(int*) * al->y_mx_map + 1)
	while (i <= al->y_mx_map)
	{
		if (!(tmp_int[i] = (int *)malloc(sizeof(int *) * al->x_mx_map)))
		{
			//free_tmp (**tmp) ft_free_tab;
			return (EXIT_FAILURE);
		}
		ft_bzero(tmp_int[i], sizeof(int) * al->x_mx_map);
		i++;
	}
}

int		assign(t_all *al, char **tmp)
{
	int		**tmp_int;

	if (al->y_mx_map == 0)
	{
		if (!(al->map = (int **)malloc(sizeof(int *) * 1))
			|| (mouv_line(al, tmp, 0) == EXIT_FAILURE))
			return (EXIT_FAILURE);
	}
	else if (mouv_tab(al, tmp, tmp_int) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		read_line(char *str, t_all *al, int y)
{
	char	**tmp;
	int		len;

	len = 0;
	tmp = NULL;
	al->y_mx_map = y;
	if ((tmp = ft_strsplit(str, ' ')) == NULL)
		return (EXIT_FAILURE);
	if ((ft_is_valid_tab(tmp, al) == 0) || (assign(al, tmp) == EXIT_FAILURE))
	{
		//free_tmp (**tmp) ft_free_tab;
		return (EXIT_FAILURE);
	}
	//ft_free_tab
	return (EXIT_SUCCESS);
}

int		do_gnl(t_all *al, char *map)
{
	int		fd;
	int		y;
	int		error;
	char	*line;

	y = 0;
	fd = 0;
	line = NULL;
	if ((fd = open(map, O_RDONLY)) == -1)
		return (-1);
	while ((error = get_next_line(fd, &line)) > 0)
	{
		if (read_line(line, al, y++) == EXIT_FAILURE)
		{
			//free_al->map
			ft_strdel(&line);
			close(fd);
			return (EXIT_FAILURE);
		}
		ft_strdel(&line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int		pars(t_all *al, char *map)
{
	int y;

	y = 0;
	if (do_gnl(al, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	print_map(al);
	return (EXIT_SUCCESS);
}
