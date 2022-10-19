/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 04:06:36 by aball             #+#    #+#             */
/*   Updated: 2022/03/28 21:49:26 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Counts the number of collectables in the game exits game if count is 0 */
int	count_collect(t_data *ptr)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (ptr->str[i])
	{
		if (ptr->str[i] == 'C')
			c++;
		i++;
	}
	if (c < 1)
	{
		ft_printf("Error\nnot much of a game without tokens now is it??\n");
		free (ptr->str);
		exit (1);
	}
	return (c);
}

/*Counts number of exits, quits game if there isn't an exit*/
void	count_e(t_data *ptr)
{
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (ptr->str[i])
	{
		if (ptr->str[i] == 'E')
			e++;
		i++;
	}
	if (e < 1)
	{
		ft_printf("Error\nHow are you going to escape the island??\n");
		free (ptr->str);
		exit (1);
	}
}

/*Counts number of players, quits if there is more or less than 1 player*/
void	count_p(t_data *ptr)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (ptr->str[i])
	{
		if (ptr->str[i] == 'P')
			p++;
		i++;
	}
	if (p > 1)
	{
		ft_printf("Error\nCan only have one player, try again.\n");
		free (ptr->str);
		exit (1);
	}
	if (p < 1)
	{
		ft_printf("Error\nHow are you going to play a game without a player?\n");
		free (ptr->str);
		exit (1);
	}
}

/*CHeck that the make is square and has the correct amount of things*/
void	check_map(t_data *ptr)
{
	if (ptr->mh == ptr->mw)
	{
		ft_printf("Error\nThis is a square, I'd prefer a rectangle.\n");
		free (ptr->str);
		exit (1);
	}
	count_p(ptr);
	count_collect(ptr);
	count_e(ptr);
	check_lines(ptr);
}
