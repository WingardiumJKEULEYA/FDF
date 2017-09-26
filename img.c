/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:35:15 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:35:16 by jkeuleya         ###   ########.fr       */
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

void	draw_square(t_var *env, t_pts pt1, t_pts pt2, t_pts pt3)
{
	make_iso(&pt1, env);
	make_iso(&pt2, env);
	make_iso(&pt3, env);
	pline_img(env, &pt1, &pt2, altitudecolor((pt1.z > pt2.z) ? pt1.z : pt2.z));
	pline_img(env, &pt1, &pt3, altitudecolor((pt1.z > pt3.z) ? pt1.z : pt3.z));
}

void	drawing_img(t_var *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->xx - 1)
	{
		j = 0;
		while (j < env->yy - 1)
		{
			draw_square(env, \
					focus_ptr(i, j, env->map[i][j]), \
					focus_ptr(i + 1, j, env->map[i + 1][j]), \
					focus_ptr(i, j + 1, env->map[i][j + 1]));
			draw_square(env, \
					focus_ptr(i + 1, j + 1, env->map[i + 1][j + 1]), \
					focus_ptr(i + 1, j, env->map[i + 1][j]), \
					focus_ptr(i, j + 1, env->map[i][j + 1]));
			j++;
		}
		i++;
	}
}
