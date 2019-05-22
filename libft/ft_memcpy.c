/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:12:02 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 11:25:08 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_memcpy
** copy n bytes from src to dest
** -
** takes a pointer to source and dest, and how much memory is to move
** return dest
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	while (n--)
		*((unsigned char *)dest + i1++) = *((unsigned char *)src + i2++);
=======
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t count;

	count = 0;
	while (count < n)
	{
		((unsigned char*)dest)[count] = ((unsigned char*)src)[count];
		count++;
	}
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
	return (dest);
}
