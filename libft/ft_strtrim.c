/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:29:10 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 17:09:47 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static int	ft_strtrimlen(char const *s)
{
	int i;
	int i2;

	if (!s)
		return (0);
	i = 0;
	i2 = ft_strlen(s);
	while (ft_isspace(s[i]))
		i++;
	if (i == i2)
		return (0);
	while (ft_isspace(s[--i2]))
		;
	return (i2 - i + 1);
=======
static int	ft_blank(char s)
{
	if (s == ' ' || s == ',' || s == '\n' || s == '\t')
		return (1);
	return (0);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}

char		*ft_strtrim(char const *s)
{
<<<<<<< HEAD
	char	*str;
	int		i;
	int		i2;

	i = 0;
	if (!s)
		return (0);
	i2 = ft_strtrimlen(s);
	if (!(str = ft_strnew(i2)))
		return (0);
	while (ft_isspace(s[i]))
		i++;
	ft_strncpy(str, s + i, i2);
	return (str);
=======
	int		start;
	int		end;
	char	*result;

	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (ft_blank(s[start]) && start < end)
		start++;
	if (start == end)
	{
		if (!(result = ft_strsub(s, 0, 0)))
			return (NULL);
		return (result);
	}
	while (ft_blank(s[end - 1]) && end > 0)
		end--;
	result = ft_strsub(s, start, end - start);
	return (result);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
