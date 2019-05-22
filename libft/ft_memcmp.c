/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:15:25 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 10:59:34 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
<<<<<<< HEAD
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (t1[i] == t2[i])
		{
			i++;
			n--;
		}
		else
			return (t1[i] - t2[i]);
=======
	size_t			count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *)s1)[count] != ((unsigned char *)s2)[count])
		{
			return (((unsigned char *)s1)[count] -
				((unsigned char *)s2)[count]);
		}
		count++;
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
	}
	return (0);
}
