/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:39:35 by aball             #+#    #+#             */
/*   Updated: 2022/03/22 20:46:52 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Read the map from file given and measures the hight and width of the map */
char	*map_read(t_data *ptr)
{
	char	*str;
	char	*temp;
	char	*check;
	int		c;

	ptr->fd = open(ptr->map_file, O_RDONLY);
	if (ptr->fd < 0)
		return (NULL);
	str = get_next_line(ptr->fd);
	c = 0;
	check = (char *)malloc(1);
	while (check)
	{
		free (check);
		temp = ft_strdup(str);
		free (str);
		check = get_next_line(ptr->fd);
		str = my_strjoin(temp, check);
		free (temp);
		c++;
	}
	ptr->mh = c;
	ptr->mw = nl_strlen(str);
	close (ptr->fd);
	return (str);
}
