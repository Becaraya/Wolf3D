/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:43:10 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 10:21:32 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int		ft_tolower(int arg)
{
	return (arg >= 'A' && arg <= 'Z' ? arg + 'a' - 'A' : arg);
=======
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
