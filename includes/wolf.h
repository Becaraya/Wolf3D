/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:52 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/27 10:36:29 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <SDL.h>

typedef struct		s_all
{
	int				x_mx_map;
	int				y_mx_map;
	int				**map;
}					t_all;

int		pars(t_all *all,char *map);
int		len_tn(char **tmp);
int		*intsub(t_all *al, int i, int j);
void	ft_free_tab(char **str);

#endif
