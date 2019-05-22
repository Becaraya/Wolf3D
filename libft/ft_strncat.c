/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:12:35 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/07 08:43:04 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char	*ft_strncat(char *dest, const char *srcc, int nb)
{
	char *src;
	char *poi;

	src = (char *)srcc;
	poi = dest;
	while (*dest)
		dest++;
	while (*src && nb > 0)
	{
		*dest = *src;
		src++;
		dest++;
		nb--;
	}
	*dest = 0;
	return (poi);
=======
char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && nb != 0)
	{
		dest[i] = src[j];
		j++;
		i++;
		nb--;
	}
	dest[i] = '\0';
	return (dest);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
