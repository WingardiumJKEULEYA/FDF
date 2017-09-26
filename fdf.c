/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:34:05 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:34:07 by jkeuleya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <mlx.h>
#include "fdf.h"
#include "fill.h"
#include "libft/includes/libft.h"
#include "get_next_line.h"

void	lst_to_map(t_list *lst, t_var *env, int x, int y)
{
	int			**map;
	t_list		*tmp;
	t_pts		*pt;
	int			i;

	i = 0;
	tmp = lst;
	map = (int **)malloc(sizeof(int *) * x);
	while (i < x)
	{
		map[i] = (int *)malloc(sizeof(int) * y);
		i++;
	}
	while (tmp)
	{
		pt = tmp->content;
		if (pt->x < x && pt->y < y)
			map[pt->x][pt->y] = pt->z;
		tmp = tmp->next;
	}
	env->map = map;
	env->c = 500 / (x + y);
	env->xfinal = x * env->c * 2;
	env->yfinal = y * env->c;
	env->zfinal = 1;
}

void	parsing(int fd, t_var *env)
{
	int		i;
	int		j;
	t_list	*pts;
	char	*line;
	char	**lines;

	i = 0;
	pts = NULL;
	if (fd <= 0)
		endof("Error when openning file.");
	while (get_next_line(fd, &line))
	{
		lines = ft_strsplit(line, ' ');
		j = 0;
		while (lines[j] != NULL)
		{
			ft_lstadd(&pts, ft_lstnew(new_ptr(j, i, \
				ft_atoi(lines[j])), sizeof(t_pts)));
			j++;
		}
		i++;
	}
	env->xx = j;
	env->yy = i;
	lst_to_map(pts, env, j, i);
}

int		draw(t_var *env)
{
	filling_img(env, 0);
	drawing_img(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		mouse(int button, int x, int y, t_var *env)
{
	(void)x;
	(void)y;
	if (button == 4)
		env->zfinal /= 1.01;
	else if (button == 5)
		env->zfinal *= 1.01;
	draw(env);
	return (0);
}

int		key(int key, t_var *env)
{
	if (key == 65307)
		endof("User exit.");
	else if (key == 65362)
		env->yfinal -= 20;
	else if (key == 65364)
		env->yfinal += 20;
	else if (key == 65361)
		env->xfinal -= 20;
	else if (key == 65363)
		env->xfinal += 20;
	else if (key == 65365)
		env->c *= 1.1;
	else if (key == 65366)
		env->c /= 1.1;
	else
		ft_putendl(ft_itoa(key));
	draw(env);
	return (0);
}
