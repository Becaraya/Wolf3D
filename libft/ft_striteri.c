/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:55:46 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/14 14:16:13 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
<<<<<<< HEAD
	int i;

	i = 0;
	if (s && f)
		while (*s)
			f(i++, s++);
=======
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (!s || !f)
		return ;
	while (*s != '\0')
	{
		(f(count, s));
		count++;
		s++;
	}
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
