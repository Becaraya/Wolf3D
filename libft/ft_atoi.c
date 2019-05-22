/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:26:16 by becaraya          #+#    #+#             */
/*   Updated: 2019/03/29 11:06:41 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int		ft_atoi(const char *strc)
{
	char		*str;
	unsigned	r;
	int			s;

	str = (char *)strc;
	while (*str == '\f' || *str == '\n' || *str == '\r' || *str == '\v' ||
		*str == '\t' || *str == ' ')
		str++;
	r = 0;
	s = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (r * s);
=======
int		ft_atoi(const char *str)
{
	int			i;
	int			k;
	int			negatif;
	long long	result;

	i = 0;
	k = 0;
	negatif = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	negatif = (str[i] == '-') ? -1 : 1;
	(str[i] == '+' || str[i] == '-') ? i++ : 0;
	while (str[i] <= 57 && str[i] >= 48)
	{
		result = result * 10 + (str[i++] - 48);
		if (result < 0)
			return (negatif == -1 ? 0 : -1);
	}
	return ((int)result * negatif);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
