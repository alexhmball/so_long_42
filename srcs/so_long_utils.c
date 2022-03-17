/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 03:41:30 by aball             #+#    #+#             */
/*   Updated: 2022/03/17 19:59:47 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nl_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

int	count_lines(char *s)
{
	int		i;
	int		nl;

	i = 0;
	nl = 1;
	while (s[i])
	{
		if (s[i] == '\n')
			nl++;
		i++;
	}
	return (nl);
}

/*Exits program when window is closed*/
int	exit_prog(void *ptr)
{
	if (ptr == 0)
		ft_printf("Sorry, X doesn't mark the spot :(\n");
	exit (0);
	return (0);
}

/*Saves the previous position of the player*/
void	save_pos(t_data *ptr)
{
	ptr->py = ptr->y;
	ptr->px = ptr->x;
}

/*When ESC is pressed, free and exit*/
void	escape_game(t_data *ptr)
{
	d_image(ptr);
	ft_printf("Escape? There is no escape...\n");
	free (ptr->str);
	exit(0);
}
