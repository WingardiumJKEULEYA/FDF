/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:34:49 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:34:51 by jkeuleya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <mlx.h>
#include <math.h>
#include "fdf.h"
#include "fill.h"
#include "libft/includes/libft.h"
#include "get_next_line.h"

t_pts	*new_ptr(int x, int y, int z)
{
	t_pts	*pt;

	pt = (t_pts *)malloc(sizeof(t_pts));
	pt->x = x;
	pt->y = y;
	pt->z = z;
	return (pt);
}

void	pt_set(t_pts *pt, int x, int y, int z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

int		altitudecolor(int z)
{
	if (z <= -4)
		return (0x3D8189);
	else if (z <= -2)
		return (0x4BB5C1);
	else if (z <= 0)
		return (0x7FC6BC);
	else if (z <= 1)
		return (0xffe58a);
	else if (z <= 4)
		return (0x71A12F);
	else if (z <= 6)
		return (0x557A23);
	else if (z <= 8)
		return (0x896A45);
	else if (z <= 10)
		return (0xA98458);
	else if (z <= 12)
		return (0xCAA986);
	else
		return (0xEDF7F2);
}

void	filling_img(t_var *env, int clr)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->width)
	{
		j = 0;
		while (j < env->height)
		{
			ppixel_img(env, i, j, clr);
			j++;
		}
		i++;
	}
}

t_pts	focus_ptr(int x, int y, int z)
{
	t_pts	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}
