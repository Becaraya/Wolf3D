/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:46:59 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 17:37:37 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
<<<<<<< HEAD
	char	*r;
	int		i1;
	int		i2;
	int		i;

	i = 0;
	i1 = 0;
	i2 = 0;
	if (!s)
		return (0);
	if (!(r = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[i2])
		r[i1++] = f(i++, s[i2++]);
	r[i2] = 0;
	return (r);
=======
	unsigned int		i;
	char				*result;

	i = -1;
	if (!s)
		return (NULL);
	if (!(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (++i < ft_strlen(s))
		result[i] = f(i, s[i]);
	return (result);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
