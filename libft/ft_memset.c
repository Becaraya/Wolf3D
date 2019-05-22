/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:39:49 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 11:22:11 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_memset
** fill n bytes of memory with c at the s adress
** -
** takes the adress to start padding, the filler c and the number of bytes to
** pad
** return nothing
*/

void	*ft_memset(void *ptr, int c, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		*((unsigned char *)ptr + i) = (unsigned char)c;
		i++;
	}
	return (ptr);
=======
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			count;

	tmp = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		tmp[count] = (unsigned char)c;
		count++;
	}
	return (s);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
