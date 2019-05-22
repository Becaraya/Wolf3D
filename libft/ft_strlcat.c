/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:43:38 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 17:51:05 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
size_t	ft_strlcat(char *dest, const char *srcc, size_t size)
{
	char		*src;
	unsigned	nanodesu;

	src = (char *)srcc;
	if (size >= ft_strlen(dest))
		nanodesu = ft_strlen(dest) + ft_strlen(src);
	else
		return (ft_strlen(src) + size);
	while (*dest && size)
	{
		size--;
		dest++;
	}
	while (*src && size > 1)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	*dest = 0;
	return (nanodesu);
=======
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	j = dest_len;
	if (dstsize < dest_len)
		return (dstsize + src_len);
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (src_len + dest_len);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
