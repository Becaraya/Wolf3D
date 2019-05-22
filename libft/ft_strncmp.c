/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:11:43 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 16:44:34 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int		ft_strncmp(const char *s1c, const char *s2c, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)s1c;
	s2 = (unsigned char *)s2c;
	while ((*s1 || *s2) && n--)
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		if (*s1 < *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
=======
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;

	count = 0;
	while (count < n)
	{
		if ((unsigned char)s1[count] != (unsigned char)s2[count])
		{
			return ((int)(unsigned char)s1[count] - (unsigned char)s2[count]);
		}
		if (!s2[count])
			return ((int)(unsigned char)s1[count]);
		if (!s1[count])
			return ((int)-(unsigned char)s1[count]);
		count++;
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
	}
	return (0);
}
