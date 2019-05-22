/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:57:41 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/14 11:29:35 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <stdlib.h>

static int	ft_nwords(char const *s, char c)
{
	long	i;
	int		b;
	int		nb;

	i = 0;
	b = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (b == 0)
				nb++;
			b = 1;
		}
		else
			b = 0;
		i++;
	}
	return (nb);
}

static char	**ft_split(char const *s, char c)
{
	long	i;
	long	j;
	int		x;
	int		nb;
	char	**tab;

	nb = ft_nwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (0);
	i = 0;
	j = -1;
	while (++j < nb && s[i])
	{
		x = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + x] != c && s[i + x])
			x++;
		tab[j] = ft_strsub(s, i, x);
		i = i + x;
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_split(s, c));
	return (NULL);
=======

static	char	**ft_strdel_(char **as)
{
	ft_memdel((void **)as);
	return (NULL);
}

static int		ft_countword(const char *s, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		x;
	int		len;
	int		start;
	int		i;
	char	**str;

	if (!s || !(str = (char**)malloc((ft_countword(s, c) + 1) * sizeof(char*))))
		return (NULL);
	x = 0;
	i = 0;
	while (i < ft_countword(s, c))
	{
		len = 0;
		while (s[x] == c && s[x])
			x++;
		start = x;
		while (s[x] != c && s[x++])
			len++;
		if (!(str[i] = ft_strsub(s, start, len)))
			return (ft_strdel_(str));
		i++;
	}
	str[i] = NULL;
	return (str);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
