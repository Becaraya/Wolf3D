/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:51:36 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/14 11:29:44 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	if (!s)
		return (0);
	if (!(ptr = (char *)malloc(len + 1)))
		return (0);
	ft_strncpy(ptr, s + start, len);
	ptr[len] = 0;
	return (ptr);
=======

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*result;

	count = 0;
	if (!(result = ft_strnew(len)) || !s)
		return (NULL);
	while (count++ < start)
		s++;
	result = ft_strncpy(result, s, len);
	return (result);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
