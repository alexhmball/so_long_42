/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:22:31 by aball             #+#    #+#             */
/*   Updated: 2022/03/02 17:57:09 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_strchr(char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return (&ptr[i + 1]);
		i++;
	}
	if (c == '\0')
		return (&ptr[i]);
	return (0);
}

static char	*save_line(char *s)
{
	int		pos;
	int		i;
	char	*save;

	i = 0;
	if (!s)
		return (NULL);
	pos = position(s);
	save = (char *)malloc(sizeof(char) * (gnl_strlen(s) - pos + 1));
	if (!save)
		return (NULL);
	if (s[pos])
	{
		while (s[++pos])
			save[i++] = s[pos];
	}
	save[i] = '\0';
	free (s);
	if (gnl_strlen(save) == 0)
	{
		free (save);
		return (0);
	}
	return (save);
}

static char	*reading(char *temp, char *s, int fd, int rd)
{
	char	*buf;

	while (gnl_strchr(temp, '\n') == 0 && rd != 0)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		s = gnl_strdup(temp);
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = '\0';
		temp = gnl_strjoin(s, buf);
	}
	return (temp);
}

static char	*gnl_free(char *s, char *nextline)
{
	if (gnl_strlen(nextline) == 0 || !nextline)
	{
		free(s);
		free(nextline);
		return (NULL);
	}
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*temp;
	char		*nextline;
	char		*buf;
	int			rd;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	rd = read(fd, buf, BUFFER_SIZE);
	if (rd < 0)
	{
		free (buf);
		return (NULL);
	}
	buf[rd] = '\0';
	if (!s)
		temp = gnl_strdup(buf);
	else
		temp = gnl_strjoin(s, buf);
	temp = reading(temp, s, fd, rd);
	nextline = gnl_strcpy(temp);
	s = save_line(temp);
	nextline = gnl_free(s, nextline);
	return (nextline);
}
