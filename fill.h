/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:34:57 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:35:06 by jkeuleya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_H
# define FILL_H

# include "libft/includes/libft.h"

typedef struct	s_pts
{
	int			x;
	int			y;
	int			z;
}				t_pts;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*content_dt;
	double		c;
	double		zfinal;
	int			xfinal;
	int			yfinal;
	int			width;
	int			height;
	int			size_bit;
	int			**map;
	int			lenline;
	int			endof_i;
	int			xx;
	int			yy;
}				t_var;

t_pts			*new_ptr(int x, int y, int z);
t_pts			focus_ptr(int x, int y, int z);
int				altitudecolor(int z);
void			drawing_img(t_var *env);
void			make_iso(t_pts *pt, t_var *env);
void			ppixel_img(t_var *env, int x, int y, int clr);
void			pline_img(t_var *env, t_pts *pt1, t_pts *pt2, int clr);
void			filling_img(t_var *env, int clr);

#endif
