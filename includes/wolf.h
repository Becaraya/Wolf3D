/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:59:52 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/29 17:22:19 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "/Library/Frameworks/SDL.framework/Versions/Current/Headers/SDL.h"

typedef struct		s_all
{
	int				x_mx_map;
	int				y_mx_map;
	int				**map; // penser a changer en unsigned char et voir ou ca merde <3
}					t_all;

int					pars(t_all *al,char *map);
int					len_ti(char **tmp);
int					*intsub(t_all *al, int i, int j);
void				ft_free_tab(char **str);
int					ft_is_valid_str(char *str);
int					ft_is_valid_tab(char **str, t_all *al);
void				print_map(t_all *al);

#endif
