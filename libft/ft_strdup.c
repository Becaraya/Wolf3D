/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:45:10 by becaraya          #+#    #+#             */
/*   Updated: 2019/03/07 15:54:22 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <stdlib.h>

/*
** ft_strdup
** alocate a string of the right size then copy the argument's content in the
** new string
** -
** takes a string
** return a frecshly allocated string containing a copy of s
*/

char	*ft_strdup(const char *s)
{
	char *tmp;

	if (!(tmp = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	ft_strcpy(tmp, s);
	return (tmp);
=======

#include <stdio.h>

char	*ft_strdup(const char *s)
{
	int		len;
	int		count;
	char	*result;

	count = 0;
	len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * len + 1)) || !(s))
		return (NULL);
	while (count < len)
	{
		result[count] = s[count];
		count++;
	}
	result[count] = '\0';
	return (result);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
