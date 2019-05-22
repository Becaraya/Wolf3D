/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:29:18 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/10 12:30:28 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_putnbr_fd
** write a number on a given fd, but with style
** -
** takes an int to print and an int describing a fd
** return nothing
*/

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned n;

	nb < 0 ? ft_putchar_fd('-', fd) : 0;
	n = nb < 0 ? -nb : nb;
	n > 9 ? ft_putnbr_fd(n / 10, fd) : 0;
	ft_putchar_fd(n % 10 + '0', fd);
=======
void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			ft_putnbr_fd(21474, fd);
			ft_putnbr_fd(83648, fd);
			return ;
		}
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
