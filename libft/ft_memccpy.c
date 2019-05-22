/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:21:54 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/12 12:05:06 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)dst;
	t2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		t1[i] = t2[i];
		if (t1[i] == (unsigned char)c)
			return (t1 + i + 1);
		i++;
	}
	return (0);
=======
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*dest_;
	unsigned char	*src_;

	count = 0;
	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	while (count < n)
	{
		dest_[count] = src_[count];
		if (src_[count] == (unsigned char)c)
			return (dest + 1 + count);
		count++;
	}
	return (NULL);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
