/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/04/16 12:17:24 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:10:00 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/10 15:12:37 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
<<<<<<< HEAD
	char *str;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (s1 ? ft_strdup(s1) : ft_strdup(s2));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(s1), s2);
	return (str);
=======
	char	*r;

	if (s1 && s2)
	{
		if (!(r = (char *)malloc(sizeof(char) * (ft_strlen(s1)
			+ ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(r, s1);
		ft_strcat(r, s2);
		return (r);
	}
	return (NULL);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
