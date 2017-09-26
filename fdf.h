/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:34:42 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:34:43 by jkeuleya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "fill.h"

# define WIDTH 800
# define HEIGHT 600

void	endof(char *str);
void	parsing(int fd, t_var *env);
int		draw(t_var *env);
int		key(int key, t_var *env);
int		mouse(int button, int x, int y, t_var *env);

#endif
