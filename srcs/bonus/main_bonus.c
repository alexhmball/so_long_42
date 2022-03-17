/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 03:46:00 by aball             #+#    #+#             */
/*   Updated: 2022/03/17 19:13:46 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	place_player(t_data *ptr)
{
	int		save;
	char	*moves;

	save = ((t_data *)ptr)->i;
	save_pos(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, ptr->x, ptr->y);
	place_walls(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->boat, ptr->x, ptr->y);		if (((t_data *)ptr)->i > save)
	{
		moves = ft_itoa(ptr->i);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->water, 0, 0);
		mlx_string_put(ptr->mlx, ptr->win, 5, 15, 0xff00ff, moves);
		free (moves);
	}
}

static int	deal_key(int key, void *ptr)
{

	if (key == 53)
		escape_game(ptr);
	if (key == 2)
		((t_data *)ptr)->x += 32;
	if (key == 0)
		((t_data *)ptr)->x -= 32;
	if (key == 13)
		((t_data *)ptr)->y -= 32;
	if (key == 1)
		((t_data *)ptr)->y += 32;
	if ((key >= 0 && key <= 2) || key == 13)
	{
		((t_data *)ptr)->i++;
		place_player(ptr);

	}
	return (0);
}

// /* displays number of moves in top left of window */
// static int	render_next_frame(t_data *ptr)
// {
// 	char	*moves;

// 	moves = ft_itoa(ptr->i);
// 	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->water, 0, 0);
// 	mlx_string_put(ptr->mlx, ptr->win, 5, 15, 0xff00ff, moves);
// 	free (moves);
// 	return (0);
// }

/* initialize images */
static void	make_image(t_data *ptr)
{
	int		h;
	int		w;

	h = 32;
	w = 32;
	ptr->win = mlx_new_window(ptr->mlx, ptr->mw * 32, ptr->mh * 32, "Pirate");
	ptr->boat = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/player.xpm", &h, &w);
	ptr->chest = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/chest.xpm", &h, &w);
	ptr->sand = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/sand.xpm", &h, &w);
	ptr->water = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/water.xpm", &h, &w);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "srcs/imgs/exit.xpm", &h, &w);
	ptr->c = count_collect(ptr);
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
		ptr.str = map_read(&ptr);
		if (ptr.str == NULL)
		{
			ft_printf("Error\nThis is not a map.");
			free (ptr.str);
			exit (0);
		}
		check_map(&ptr);
		ptr.mlx = mlx_init();
		make_image(&ptr);
		place_tile(&ptr);
		mlx_key_hook(ptr.win, deal_key, &ptr);
		//mlx_loop_hook(ptr.mlx, render_next_frame, &ptr);
		mlx_hook(ptr.win, 17, 0, exit_prog, (void *)0);
		mlx_loop(ptr.mlx);
	}
	return (0);
}
