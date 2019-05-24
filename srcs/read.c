/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:13:45 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/24 15:19:05 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

int		len_tn(char **tmp)
{
	int		count;

	count = 0;
	while(tmp[count])
		count++;
	return (count);
}

int		read_line(char *line, t_all *al, int y)
{
	int		i;
	int		len_lgn;
	char	**tmp;

	i = 0;
	if ((tmp = ft_strsplit(str, ' ')) == NULL || ((len_lgn = len_tb(tmp)) == 0))
		return (EXIT_FAILURE);
	if (al->x_mx_map == 0 && (!(al->map = (int**)malloc(sizeof(int*)))))
	{
		ft_free_tab(tmp);
		free(tmp);
		return (EXIT_FAILURE);
	}
	if ((al->x_mx_map != 0 && al->x_mx_map != len_lgn)
		|| (!(al->map[y] = (int*)malloc(sizeof(int) * len_lgn))))
	{
		//fct_free(le tableau d int deja malloc)
		ft_free_tab(tmp);
		free(tmp);
		return (EXIT_FAILURE);
	}
	ft_free_tab(tmp);
	free(tmp);
	return ((i == 0) ? EXIT_FAILURE : EXIT_SUCCESS);
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

	y = do_gnl(al, map);
	return (EXIT_SUCCESS);
}
