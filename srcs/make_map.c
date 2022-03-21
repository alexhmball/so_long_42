/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 04:39:28 by aball             #+#    #+#             */
/*   Updated: 2022/03/21 17:21:11 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Places walls and keeps player from going into them*/
static int	if_one(t_data *ptr, int x, int y)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->water, x, y);
	if (ptr->x == x && ptr->y == y)
	{
		ptr->x = ptr->px;
		ptr->y = ptr->py;
		ptr->i--;
	}
	return (32);
}

/*places exit tile and exit if player has collected all items*/
static int	if_e(t_data *ptr, int x, int y)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, x, y);
	if (ptr->x == x && ptr->y == y && ptr->c == 0)
	{
		ft_printf("Congrats, you won the game in %d moves :)\n", ptr->i);
		d_image(ptr);
		free (ptr->str);
		exit (0);
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit, x, y);
	if ((ptr->x == x && ptr->y == y) || (ptr->px == x && ptr->py == y))
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->boat, x, y);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit, x, y);
	return (32);
}

/*places then removes collectable when players moves ontop of it*/
static int	if_c(t_data *ptr, int x, int y, int i)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, x, y);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->chest, x, y);
	if (ptr->x == x && ptr->y == y)
	{
		ptr->c--;
		ptr->str[i] = '0';
	}
	return (32);
}

/*Places sand tiles*/
static int	if_zero(t_data *ptr, int x, int y)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, x, y);
	return (32);
}

/*Places tiles according to map file*/
void	place_walls(t_data *ptr)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	mlx_clear_window(ptr->mlx, ptr->win);
	while (ptr->str[i])
	{
		if (ptr->str[i] == '1')
			x += if_one(ptr, x, y);
		else if (ptr->str[i] == 'C')
			x += if_c(ptr, x, y, i);
		else if (ptr->str[i] == 'E')
			x += if_e(ptr, x, y);
		else if (ptr->str[i] == '0' || ptr->str[i] == 'P')
			x += if_zero(ptr, x, y);
		else if (ptr->str[i] == '\n')
		{
			y += 32;
			x = 0;
		}
		i++;
	}
}
