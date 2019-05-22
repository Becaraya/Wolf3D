/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:45:13 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 10:45:47 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_memmove
** move n bytes from src bloc to dest, overlap is possible
** -
** takes the adress to dest and src blocs, and the number of bytes to move
** return dest
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long i;

	i = 0;
	if (!src)
	{
		ft_bzero(dest, n);
		return (0);
	}
	if (src > dest)
		while (i < (long)n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	if (src < dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
=======
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (dest > src)
	{
		while (count < n)
		{
			((unsigned char*)dest)[n - 1] = ((unsigned char*)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (count < n)
		{
			((unsigned char*)dest)[count] = ((unsigned char*)src)[count];
			count++;
		}
	}
	return ((unsigned char *)dest);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
