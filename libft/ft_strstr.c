/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:20:15 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/07 11:09:30 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;

	i = 0;
<<<<<<< HEAD
	while (str[i])
	{
		if (!ft_strncmp((char *)str + i, (char *)to_find,
						ft_strlen(to_find)))
			return ((char *)str + i);
		i++;
	}
	if (!str[0] && !to_find[0])
		return ((char *)str);
	return (0);
=======
	while (str[i] == to_find[i] && str[i] != '\0')
		i++;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (str[i] == '\0')
		return (NULL);
	return (ft_strstr(str + 1, to_find));
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
