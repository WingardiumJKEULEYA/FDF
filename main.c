/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeuleya <jkeuleya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:35:21 by jkeuleya          #+#    #+#             */
/*   Updated: 2015/01/21 14:35:23 by jkeuleya         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_var	env;
	int		fd;

	if (ac != 2)
		endof("Please specify a file to open.");
	fd = open(av[1], O_RDONLY);
	parsing(fd, &(env));
	env.mlx = mlx_init();
	if (env.mlx == NULL)
		return (0);
	env.width = WIDTH;
	env.height = HEIGHT;
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Fdf");
	env.img = mlx_new_image(env.mlx, env.width, env.height);
	env.content_dt = mlx_get_data_addr(env.img, &(env.size_bit), \
			&(env.lenline), &(env.endof_i));
	mlx_expose_hook(env.win, draw, &env);
	mlx_key_hook(env.win, key, &env);
	mlx_mouse_hook(env.win, mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}

void	endof(char *str)
{
	ft_putendl(str);
	exit(3);
}
