/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:25:38 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 17:27:43 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
<<<<<<< HEAD
	char	*r;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	if (!s)
		return (0);
	if (!(r = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[i2])
		r[i1++] = f(s[i2++]);
	return (r);
=======
	char	*result;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		result[i] = f(s[i]);
	return (result);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
