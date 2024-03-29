/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:26:20 by aball             #+#    #+#             */
/*   Updated: 2022/04/08 01:59:53 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	d_image(t_data *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_destroy_image(ptr->mlx, ptr->chest);
	mlx_destroy_image(ptr->mlx, ptr->sand);
	mlx_destroy_image(ptr->mlx, ptr->water);
	mlx_destroy_image(ptr->mlx, ptr->exit);
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit (0);
}
