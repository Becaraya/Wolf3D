/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:46:14 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/06 16:46:23 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_strcpy
** copy a string in another
** -
** takes a destination string and a source string
** return dest
*/

char	*ft_strcpy(char *dest, const char *src)
{
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	while (src[i2])
		dest[i1++] = src[i2++];
	dest[i1] = 0;
=======
char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
	return (dest);
}
