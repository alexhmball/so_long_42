/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:49:23 by aball             #+#    #+#             */
/*   Updated: 2022/03/17 19:30:29 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_if(t_data *ptr, int i, int x, int y)
{
	if (ptr->str[i] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->water, x, y);
	if (ptr->str[i] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, x, y);
	if (ptr->str[i] == 'C')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, x, y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->chest, x, y);
	}
	if (ptr->str[i] == 'P')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, x, y);
		ptr->x = x;
		ptr->y = y;
		ptr->px = x;
		ptr->py = y;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->boat, x, y);
	}
}

/*Places tiles in location specified by the map*/
void	place_tile(t_data *ptr)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (ptr->str[i])
	{
		check_if(ptr, i, x, y);
		if (ptr->str[i] == 'E')
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sand, x, y);
			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit, x, y);
		}
		if (ptr->str[i] == '\n')
		{
			x = 0;
			y += 32;
		}
		if (ptr->str[i] != '\n')
			x += 32;
		i++;
	}
}
