/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/04/16 11:50:23 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:42:01 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 12:35:29 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_strchr
** find and return the first occurence of c in s
** -
** takes a string and a char to search
** return a pointer to the first occurence of c, or 0 if not found
*/

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c)
	{
		if (!s[i++])
			return (0);
	}
	return ((char *)s + i);
=======
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
