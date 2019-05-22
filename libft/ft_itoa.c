/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	len(int n)
{
	int l;

	l = (n >= 0 ? 1 : 2);
	while (n > 9 || n < -9)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static int	power(int size)
{
	int i;

	i = 1;
	while (size-- > 0)
		i *= 10;
	return (i);
}

static void	dew_it(char *str, int size, long n)
{
	n = n > 0 ? n : -n;
	while (size)
		*(str++) = n / power(--size) % 10 + '0';
	*str = 0;
}

char		*ft_itoa(int n)
{
	char *str;

	if (!(str = (char *)malloc(len(n) + 1)))
		return (0);
	if (n < 0)
		*str = '-';
	dew_it(str + (n < 0 ? 1 : 0), len(n) - (n < 0 ? 1 : 0), (long)n);
	return (str);
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:36:21 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/14 13:34:15 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_result(char *result, long int nbr, int n)
{
	if (n < 0)
		result[1] = nbr + '0';
	else
		result[0] = nbr + '0';
	return (result);
}

static int		ft_len(int n)
{
	long int		nbr;
	int				i;

	nbr = n;
	i = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr / 10 > 9)
	{
		i++;
		nbr = nbr / 10;
	}
	if (n < 0)
		return (i + 2);
	else
		return (i + 1);
}

char			*ft_itoa(int n)
{
	long int		nbr;
	int				neg;
	int				i;
	char			*result;

	nbr = n;
	neg = 0;
	i = 0;
	neg = (nbr < 0) ? -1 : 0;
	if (!(result = (char *)malloc(sizeof(char) * ft_len(n) + 1 - neg)))
		return (NULL);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		result[i] = '-';
		i++;
	}
	while ((ft_len(n) - i) > 0 && n != 0 && nbr > 9)
	{
		result[ft_len(n) - i - neg] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	result[ft_len(n) + 1] = '\0';
	return (ft_result(result, nbr, n));
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
