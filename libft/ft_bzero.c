/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/04/16 17:01:04 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:52:07 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/09 11:23:19 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*
** ft_bzero  F 4 S T  A S  F U C C
** fill n bytes of memory with 0 at the s adress, but f4ster than my bullet
** -
** takes the adress to start padding and the number of bytes to pad
** return nothing
*/

void	ft_bzero(void *s, size_t n)
{
	while (n % 8)
	{
		n--;
		*((char *)s + n) = 0;
	}
	while (n >= 8)
	{
		n -= 8;
		*((long *)s + n / 8) = 0;
	}
=======
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
