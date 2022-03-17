/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:36:33 by aball             #+#    #+#             */
/*   Updated: 2022/03/17 19:07:07 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Checks the length of the lines are the same*/
static void	check_line_len(t_data *ptr, char *str, int i)
{
	if (ft_strchr(str, '\n') == 0 && ft_strlen(str) != (size_t)ptr->mw)
	{
		ft_printf("Error\nBad map, check the line length.\n");
		free (str);
		exit (0);
	}
	if (ft_strchr(str, '\n') != 0 && i - 1 != ptr->mw)
	{
		ft_printf("Error\nBad map, check the line length.\n");
		free (str);
		exit (0);
	}
	if (str[0] != '1' || str[ptr->mw - 1] != '1')
	{
		ft_printf("Error\nThis is supposed to be an island, fix the map.\n");
		free (str);
		exit (0);
	}
}

/*checks that the map is closed by walls*/
static void	check_first_last(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != '1')
		{
			ft_printf("Error\nAn island needs to be surrounded by water.\n");
			free (str);
			exit (0);
		}
		i++;
	}
}

/* checks for invalid characters*/
static int	check_char(char *str, int i)
{
	i = 0;
	while (str[i] && str)
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '\n'
			&& str[i] != 'P' && str[i] != 'C' && str[i] != 'E')
		{
			ft_printf("Error\nInvalid character.\n");
			free (str);
			exit (0);
		}
		i++;
	}
	return (i);
}

/*Checks lines are equal, contain valid characters, and map is closed by walls*/
void	check_lines(t_data *ptr)
{
	char	*str;
	char	*ret;
	int		i;
	int		c;

	ret = (char *)malloc(1);
	ptr->fd = open(ptr->map_file, O_RDONLY);
	str = get_next_line(ptr->fd);
	c = 1;
	i = 0;
	while (str)
	{
		i = check_char(str, i);
		check_line_len(ptr, str, i);
		if (c == 1)
			check_first_last(str);
		if (c == ptr->mh)
			check_first_last(str);
		ret = gnl_strjoin(ret, str);
		c++;
		str = get_next_line(ptr->fd);
	}
	close (ptr->fd);
	free (str);
}
