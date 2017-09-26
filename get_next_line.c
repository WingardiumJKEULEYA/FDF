/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:35:34 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:35:35 by jkeuleya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "get_next_line.h"

static int		gnl_linejoin(char **content, char **buff, const int n)
{
	char	*tmp;

	if ((tmp = ft_strnew(ft_strlen(*content) + n)) == NULL)
	{
		free(*content);
		free(*buff);
		return (1);
	}
	ft_strcpy(tmp, *content);
	ft_strncat(tmp, *buff, n);
	free(*content);
	*content = tmp;
	return (0);
}

static char		*gnl_readline(t_gnl **cache, const int fd)
{
	char	*buff;
	char	*new_content;
	int		n;

	if (ft_strchr((*cache)->content, '\n') != NULL)
		return ((*cache)->content);
	if ((new_content = ft_strnew(ft_strlen((*cache)->content))) == NULL)
		return (NULL);
	ft_strcpy(new_content, (*cache)->content);
	free((*cache)->content);
	if ((buff = ft_strnew(BUFF_SIZE)) == NULL)
		return (NULL);
	while (ft_strchr(buff, '\n') == NULL && (n = read(fd, buff, BUFF_SIZE)) > 0)
		if (gnl_linejoin(&new_content, &buff, n) == 1)
			return (NULL);
	free(buff);
	if (n == -1)
	{
		free(new_content);
		return (NULL);
	}
	return (new_content);
}

static t_gnl	*gnl_getcache(t_gnl **lst, const int fd)
{
	t_gnl	**tmp;

	tmp = &(*lst);
	if (lst != NULL)
		while (*tmp != NULL)
			if ((*tmp)->fd == fd)
			{
				if ((*tmp)->content == NULL)
					(*tmp)->content = ft_strnew(0);
				if ((*tmp)->content != NULL)
					(*tmp)->content = gnl_readline(&(*tmp), fd);
				return (*tmp);
			}
			else
				tmp = &((*tmp)->next);
	if ((*tmp = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	(*tmp)->fd = fd;
	(*tmp)->content = ft_strnew(0);
	(*tmp)->next = NULL;
	if ((*tmp)->content != NULL)
		(*tmp)->content = gnl_readline(&(*tmp), fd);
	return (*tmp);
}

static int		gnl_nextline(char **content, int i)
{
	char	*tmp;
	int		res;

	if ((*content)[i] != '\0')
		res = 1;
	else
		res = 0;
	i = i + res;
	tmp = ft_strsub(*content, i, ft_strlen(*content) - i);
	free(*content);
	*content = tmp;
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*cache;
	int				i;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((cache = gnl_getcache(&lst, fd)) == NULL || cache->content == NULL)
		return (-1);
	i = 0;
	while (cache->content[i] != '\n' && cache->content[i] != '\0')
		i = i + 1;
	if ((*line = ft_strsub(cache->content, 0, i)) == NULL)
		return (-1);
	return (gnl_nextline(&(cache->content), i));
}
