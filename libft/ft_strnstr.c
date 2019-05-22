/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:07 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/15 18:41:56 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
<<<<<<< HEAD
	int i;

	i = 0;
	if (!*(char *)to_find || !to_find)
		return ((char *)str);
	if (!len)
		return (0);
	if (len < ft_strlen(to_find))
		return (0);
	len -= ft_strlen(to_find);
	while (str[i] && len-- + 1)
	{
		if (!ft_strncmp((char *)str + i, (char *)to_find, ft_strlen(to_find)))
			return ((char *)str + i);
		i++;
	}
	return (0);
=======
	size_t i;

	i = 0;
	while (str[i] == to_find[i] && str[i] != '\0' && (i < len))
		i++;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (str[i] == '\0' || len == i)
		return (NULL);
	return (ft_strnstr(str + 1, to_find, (len - 1)));
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
