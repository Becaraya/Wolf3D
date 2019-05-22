/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1c, const char *s2c)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)s1c;
	s2 = (unsigned char *)s2c;
	while (*s1 || *s2)
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		if (*s1 < *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:13:14 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 15:23:03 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int result;

	i = 0;
	while ((int)s1[i] != 0 && (int)s2[i] != 0 && (int)s1[i] == (int)s2[i])
		i++;
	result = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (result);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
