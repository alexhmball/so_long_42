/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:17:16 by aball             #+#    #+#             */
/*   Updated: 2022/10/19 15:23:32 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC_KEY 53
# define LEFT 0
# define RIGHT 2
# define UP 13
# define DOWN 1

# include "../minilibx_opengl/mlx.h"
# include "../minilibx_opengl/mlx_opengl.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*sand;
	void	*water;
	void	*player;
	void	*chest;
	void	*exit;
	int		c;
	int		fd;
	int		px;
	int		py;
	int		x;
	int		y;
	int		i;
	int		mh;
	int		mw;
	char	*str;
	char	*map_file;
}			t_data;

void	place_tile(t_data *ptr);
char	*find_w_h(t_data *ptr);
int		nl_strlen(char *s);
int		count_lines(char *s);
void	check_lines(t_data *ptr);
char	*map_read(t_data *ptr);
char	*my_strjoin(const char *s1, const char *s2);
void	place_walls(t_data *ptr);
int		count_collect(t_data *ptr);
void	count_p(t_data *ptr);
void	check_map(t_data *ptr);
void	save_pos(t_data *ptr);
int		exit_prog(void *ptr);
void	escape_game(t_data *ptr);
char	*map_read(t_data *ptr);
void	d_image(t_data *ptr);
void	check_file_ext(t_data *ptr);

#endif
