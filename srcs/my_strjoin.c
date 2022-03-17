/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:04:29 by aball             #+#    #+#             */
/*   Updated: 2021/12/14 01:07:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*if_s2_null(char *joint, int i)
{
	joint[i] = '\0';
	return (joint);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	joint = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (joint == NULL)
		return (0);
	while (s1[i])
	{
		joint[i] = s1[i];
		i++;
	}
	if (!s2)
		return (if_s2_null(joint, i));
	while (s2[j])
	{
		joint[i++] = s2[j++];
	}
	joint[i] = '\0';
	return (joint);
}
