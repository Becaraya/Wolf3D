/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:37:31 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/10 11:55:04 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <unistd.h>

/*
** ft_putchar
** write a char on stdout
** -
** takes a char
** return nothing
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
=======

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
