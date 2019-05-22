/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:37:16 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:59:23 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/06 18:00:26 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_putnbr
** print an int
** -
** takes an int
** return nothing
*/

void	ft_putnbr(int nb)
{
	unsigned n;

	nb < 0 ? ft_putchar('-') : 0;
	n = nb < 0 ? -nb : nb;
	n > 9 ? ft_putnbr(n / 10) : 0;
	ft_putchar(n % 10 + '0');
=======
void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putnbr(21474);
			ft_putnbr(83648);
			return ;
		}
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
