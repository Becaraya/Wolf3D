/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:20:41 by pitriche          #+#    #+#             */
/*   Updated: 2019/07/01 07:52:15 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			err_tex(t_all *al)
{
	ft_putstr_fd("Tu veut tbattr ?? QUI T'AS DIT DE TOUCHER LES TEXTURES\n", 2);
	yeet(al);
}

void			for_huehue(t_all *al, int fd, unsigned int *pix, unsigned char
	*buf)
{
	int i;
	int j;

	j = TEXT_SIZE - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < TEXT_SIZE)
		{
			if (read(fd, buf, 3) != 3)
				err_tex(al);
			pix[j * TEXT_SIZE + i] = (buf[2] << 16) | (buf[1] << 8)
			| buf[0];
			i++;
		}
		j--;
	}
}

unsigned int	*parse_tex(t_all *al, char *name)
{
	unsigned int	*pix;
	int				fd;
	unsigned char	buf[64];

	if ((fd = open(name, O_RDONLY)) < 0)
		err_tex(al);
	if (!(pix = ft_memalloc(TEXT_SIZE * TEXT_SIZE * sizeof(int))))
		yeet(al);
	if (read(fd, buf, 14) != 14 || buf[10] - 14 > 64)
		err_tex(al);
	read(fd, buf, buf[10] - 14);
	for_huehue(al, fd, pix, buf);
	close(fd);
	return (pix);
}
