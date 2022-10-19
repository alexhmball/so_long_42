/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 03:41:30 by aball             #+#    #+#             */
/*   Updated: 2022/04/08 01:38:36 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	nl_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

/*Checks that the mapfile is .ber*/
void	check_file_ext(t_data *ptr)
{
	int		i;
	char	*map;
	int		len;
	char	temp;

	len = ft_strlen(ptr->map_file);
	len--;
	i = 0;
	map = ft_strdup(ptr->map_file);
	while (i < len)
	{
		temp = map[i];
		map[i] = map[len];
		map[len] = temp;
		i++;
		len--;
	}
	if (ft_strncmp(map, "reb.", 4))
	{
		ft_printf("Error\nThis is not a .ber file");
		free (ptr->str);
		free (map);
		exit (1);
	}
	free (map);
}

/*Exits program when window is closed*/
int	exit_prog(void *ptr)
{
	if (ptr == 0)
		ft_printf("Sorry, X doesn't mark the spot :(\n");
	free (((t_data *)ptr)->str);
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
	ft_printf("Escape? There is no escape...\n");
	d_image(ptr);
	free (ptr->str);
	exit(0);
}
