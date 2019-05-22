/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:48:09 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 13:10:13 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
<<<<<<< HEAD
	int		i;

	i = ft_strlen(s) - 1;
	if (!s || (!*(char *)s && c))
		return (0);
	if (!c)
		return ((char *)s + i + 1);
	while (s[i] != c)
	{
		if (!i--)
			return (0);
	}
	return ((char *)s + i);
=======
	int i;
	int count;

	i = ft_strlen(s);
	count = 0;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			while (count < i)
			{
				s++;
				count++;
			}
			return ((char *)s);
		}
		else
			i--;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
