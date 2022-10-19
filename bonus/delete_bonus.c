/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:26:20 by aball             #+#    #+#             */
/*   Updated: 2022/03/22 21:15:08 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	d_image(t_data *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->p1);
	mlx_destroy_image(ptr->mlx, ptr->p2);
	mlx_destroy_image(ptr->mlx, ptr->chest);
	mlx_destroy_image(ptr->mlx, ptr->sand);
	mlx_destroy_image(ptr->mlx, ptr->water);
	mlx_destroy_image(ptr->mlx, ptr->exit);
}
