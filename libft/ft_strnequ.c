/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:09:26 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 15:48:17 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
		return (!ft_strncmp((char *)s1, (char *)s2, n));
	return (0);
=======
int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t count;

	count = 0;
	while (count < n)
	{
		if (ft_memcmp(s1, s2, count) == 0 && s1 != '\0' && s2 != '\0')
			count++;
		else
			return (0);
	}
	return (1);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
