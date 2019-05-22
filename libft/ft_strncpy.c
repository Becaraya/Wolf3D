/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:46:51 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 11:18:23 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_strncpy
** copies n chars of src, to dest. stops at n or end of src
** -
** takes a source string and a dest one
** return dest
*/

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;

	i = 0;
	while (n-- && src[i])
=======
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] && n > i)
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
	{
		dest[i] = src[i];
		i++;
	}
<<<<<<< HEAD
	while (n + 1)
	{
		dest[i++] = 0;
		n--;
=======
	while (i < n)
	{
		dest[i] = '\0';
		i++;
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
	}
	return (dest);
}
