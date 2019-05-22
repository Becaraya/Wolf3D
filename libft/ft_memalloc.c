/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:40:28 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:31:08 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/16 09:11:52 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <stdlib.h>

/*
** ft_memalloc
** allocates size bytes, and fill them with 0s
** -
** takes the amount of bytes to allocate
** return the memory bloc with allocated memory
*/

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!(ptr = malloc(size)))
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
=======

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if (!(mem = malloc(size)))
		return (0);
	ft_bzero(mem, size);
	return ((void *)mem);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
