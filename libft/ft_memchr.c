/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:50:25 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 15:33:50 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
<<<<<<< HEAD
	int i;

	i = 0;
	if (!n)
		return (0);
	while (n--)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
=======
	size_t count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *)s)[0] == (unsigned char)c)
			return ((void *)s);
		s++;
		count++;
	}
	return (NULL);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
