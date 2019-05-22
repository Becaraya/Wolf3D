/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/13 17:23:09 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:33:12 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/13 10:13:21 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
=======

void	ft_memdel(void **ap)
{
	if (!((void **)ap))
		return ;
	free(*ap);
	*ap = NULL;
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
