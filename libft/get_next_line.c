/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/18 17:26:01 by pitriche         ###   ########.fr       */
=======
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:55:34 by becaraya          #+#    #+#             */
/*   Updated: 2019/03/11 14:25:10 by becaraya         ###   ########.fr       */
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <unistd.h>
#include <stdlib.h>

/*
** isolate [TESTED]
** find the line to be returned from the static list, duplicates it and store
** it in line, then move backward the string the length of the picked string
** plus the newline. If no characters are left an empty string will be
** allocated.
** -
** takes a pointer to the line string and the current part of the static list
** return 1 if a line was cut, 0 if the string is empty and -1 if the malloc
** fails
*/

static int		isolate(char **line, t_list *cur)
{
	char *next_line;

	if (!*(char *)cur->data)
		return (0);
	if (!(next_line = ft_strchr((char *)cur->data, '\n')))
	{
		if (!(*line = ft_strdup((char *)cur->data)))
			return (-1);
		free(cur->data);
		if (!(cur->data = (void *)ft_strnew(0)))
			return (-1);
	}
	else
	{
		if (!(*line = ft_strnew(next_line - (char *)cur->data)))
			return (-1);
		ft_strncpy(*line, (char *)cur->data, next_line -
		(char *)cur->data);
		ft_strcpy((char *)cur->data, next_line + 1);
	}
	return (1);
}

/*
** read_fd [untested]
** read the fd one buffer, then merge the read line in the static list.
** -
** takes the fd to read and the current part of the static list
** return the read's return, and -1 if malloc fails.
*/

static int		read_fd(int fd, t_list *cur)
{
	char	*buf;
	char	*content;
	int		ret;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
	{
		free((void *)buf);
		return (ret);
	}
	content = (char *)cur->data;
	if (!(cur->data = (void *)ft_strjoin(cur->data, buf)))
	{
		free((void *)buf);
		return (-1);
	}
	free((void *)content);
	free((void *)buf);
	return (ret);
}

/*
** fd_find [TESTED / MODIFIED]
** finds the corresponding element in the static list. If no element correspond
** to the fd, one is created
** -
** takes the fd, the static list and a pointer to the static list
** return the corresponding element, and 0 if malloc fails.
*/

static t_list	*fd_find(int fd, t_list *list, t_list **root)
{
	t_list *tmp;

	if (!list)
	{
		if (!(tmp = ft_lstnew_empty()))
			return (0);
		if (!(tmp->data = (void *)ft_strnew(0)))
			return (0);
		tmp->d_size = (size_t)fd;
		ft_lstadd(root, tmp);
		return (*root);
	}
	if ((int)list->d_size == fd)
		return (list);
	else
		return (fd_find(fd, list->next, root));
}

/*
** get_next_line [TESTED]
** read one line in a file descriptor
** -
** takes the fd and a pointer to the pointer where the line shall be stored
** return 1 if a line was read, 0 if there is no more lines to read (aka read
** return 0) and -1 if read encounters an error or one of the mallocs fails
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*cur;
	int				ret;

	if (!(cur = fd_find(fd, list, &list)))
		return (-1);
	while (!ft_strchr(cur->data, '\n'))
	{
		ret = read_fd(fd, cur);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
	}
	return (isolate(line, cur));
=======

static int		ft_readfd(const int fd, char **str)
{
	int			ret;
	char		c[BUFF_SIZE + 1];
	char		*tmp;
	size_t		i;

	i = 0;
	while ((ret = read(fd, c, BUFF_SIZE)) > 0)
	{
		c[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], c);
		free(str[fd]);
		str[fd] = tmp;
		while (str[fd][i] != '\n' && str[fd][i] != '\0')
			i++;
		if (str[fd][i] == '\n')
			break ;
	}
	return (ret);
}

static void		ft_assign_line(char **str, const int fd, char **line, int i)
{
	char *tmp;

	tmp = NULL;
	if (str[fd][i] != '\0')
	{
		tmp = str[fd];
		*line = ft_strsub(tmp, 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		ft_strdel(&tmp);
	}
}

static int		ft_line_alloc(const int fd, char **line, char **str)
{
	int			ret;
	size_t		i;

	if ((ret = ft_readfd(fd, str)) < 0)
		return (-1);
	i = 0;
	while (str[fd])
	{
		if (str[fd][0] == '\0')
			return (0);
		while (str[fd][i] != '\0' && str[fd][i] != '\n')
			i++;
		if (i == ft_strlen(str[fd]) && (ret = ft_readfd(fd, str)) > 0)
			continue ;
		ft_assign_line(str, fd, line, i);
		return ((ret < 0) ? -1 : 1);
	}
	return ((ret < 0) ? -1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	if ((ret = ft_line_alloc(fd, line, &str[fd])) > 0)
		return (1);
	return (ret < 0 ? -1 : 0);
>>>>>>> e9d97ba64cb27f5e919a39135c8b3a3114034cf2
}
