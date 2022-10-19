/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 03:46:00 by aball             #+#    #+#             */
/*   Updated: 2022/04/04 01:16:20 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Places the player in the next position*/
static void	place_player(t_data *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, ptr->x, ptr->y);
	place_walls(ptr);
	if (ptr->flag == 0)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->p2, ptr->x, ptr->y);
		ptr->flag = 1;
	}
	else
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->p1, ptr->x, ptr->y);
		ptr->flag = 0;
	}
}

/*Moves player and outputs moves to terminal*/
static int	deal_key(int key, void *ptr)
{
	char	*m;

	save_pos(ptr);
	if (key == ESC_KEY)
		escape_game(ptr);
	if (key == RIGHT)
		((t_data *)ptr)->x += 32;
	if (key == LEFT)
		((t_data *)ptr)->x -= 32;
	if (key == UP)
		((t_data *)ptr)->y -= 32;
	if (key == DOWN)
		((t_data *)ptr)->y += 32;
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		((t_data *)ptr)->i++;
	place_player(ptr);
	m = ft_itoa(((t_data *)ptr)->i);
	mlx_string_put(((t_data *)ptr)->mlx,
		((t_data *)ptr)->win, 20, 20, WC, "Moves:");
	mlx_string_put(((t_data *)ptr)->mlx, ((t_data *)ptr)->win, 70, 20, WC, m);
	free (m);
	return (0);
}

/* Assign image variables*/
static void	make_image(t_data *ptr)
{
	int		h;
	int		w;

	h = 32;
	w = 32;
	ptr->win = mlx_new_window(ptr->mlx, ptr->mw * 32, ptr->mh * 32, "Pirate");
	ptr->chest = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/chest.xpm", &h, &w);
	ptr->sand = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/sand.xpm", &h, &w);
	ptr->water = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/water.xpm", &h, &w);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/exit.xpm", &h, &w);
	ptr->p1 = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/p1.xpm", &h, &w);
	ptr->p2 = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/p2.xpm", &h, &w);
	ptr->c = count_collect(ptr);
}

/*Check map file is valid and initialize mlx variables*/
static void	valid_map(t_data *ptr)
{
	ptr->str = map_read(ptr);
	if (ptr->str == NULL)
	{
		ft_printf("Error\nThis is not a map.");
		free (ptr->str);
		exit (1);
	}
	check_file_ext(ptr);
	check_map(ptr);
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
	{
		free (ptr->str);
		exit (1);
	}
	make_image(ptr);
	place_tile(ptr);
	mlx_string_put(((t_data *)ptr)->mlx, ((t_data *)ptr)->win, 70, 20, WC, "0");
	mlx_string_put(((t_data *)ptr)->mlx,
		((t_data *)ptr)->win, 20, 20, WC, "Moves:");
	mlx_key_hook(ptr->win, deal_key, ptr);
	mlx_hook(ptr->win, 17, 0, exit_prog, (void *)0);
	mlx_loop(ptr->mlx);
}

int	main(int ac, char **av)
{
	t_data	ptr;

	if (ac == 1)
		ft_printf("Error\nWhere's the map??\n");
	if (ac > 2)
		ft_printf("Error\nOnly one map will be accepted, nice try.\n");
	if (ac == 2)
	{
		ptr.map_file = av[1];
		ptr.fd = open(ptr.map_file, O_DIRECTORY);
		if (ptr.fd < 0)
		{
			close (ptr.fd);
			valid_map(&ptr);
		}
		else
			ft_printf("Error\nThis is a directory");
	}
	return (0);
}
