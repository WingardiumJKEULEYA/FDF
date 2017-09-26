/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:31:50 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:31:51 by jkeuleya         ###   ########.fr       */
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

void		ppixel_img(t_var *env, int x, int y, int clr)
{
	char			*data;
	unsigned int	value;

	data = env->content_dt;
	value = mlx_get_color_value(env->mlx, clr);
	if (x > 0 && x < env->width && y > 0 && y < env->height)
		ft_memcpy(data + y * env->lenline + x * (env->size_bit / 8), &value, 3);
}

static void	img_put_hline(t_var *env, t_pts *pt1, t_pts *pt2, int clr)
{
	int		i;

	i = pt1->x;
	while (i < pt2->x)
	{
		ppixel_img(env, i, pt1->y + ((pt2->y - pt1->y) * \
					(i - pt1->x)) / (pt2->x - pt1->x), clr);
		i++;
	}
}

static void	img_put_vline(t_var *env, t_pts *pt1, t_pts *pt2, int clr)
{
	int		i;

	i = pt1->y;
	while (i < pt2->y)
	{
		ppixel_img(env, pt1->x + ((pt2->x - pt1->x) * \
					(i - pt1->y)) / (pt2->y - pt1->y), i, clr);
		i++;
	}
}

void		pline_img(t_var *env, t_pts *pt1, t_pts *pt2, int clr)
{
	if (fabs(pt1->x - pt2->x) > fabs(pt1->y - pt2->y))
	{
		if (pt1->x < pt2->x)
			img_put_hline(env, pt1, pt2, clr);
		else
			img_put_hline(env, pt2, pt1, clr);
	}
	else
	{
		if (pt1->y < pt2->y)
			img_put_vline(env, pt1, pt2, clr);
		else
			img_put_vline(env, pt2, pt1, clr);
	}
}

void		make_iso(t_pts *pt, t_var *env)
{
	t_pts		tmp;

	tmp.x = pt->x;
	tmp.y = pt->y;
	tmp.z = pt->z;
	pt->x = tmp.x * 2 - tmp.y * 2;
	pt->y = tmp.x + tmp.y - tmp.z * env->zfinal;
	pt->x *= env->c;
	pt->y *= env->c;
	pt->x += env->xfinal;
	pt->y += env->yfinal;
}
