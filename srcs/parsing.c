/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/15 15:16:49 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	def_view(t_view *s_view, t_map *s_map)
{
	s_view->win_width = WIN_WIDTH;
	s_view->win_height = WIN_HEIGHT;
	s_view->img_width = s_view->win_width * 0.8;
	s_view->img_height = s_view->win_height * 0.8;
	s_view->margin_x = s_view->win_width * 0.1;
	s_view->margin_y = s_view->win_height * 0.1;
	s_view->dotX = s_view->img_width / s_map->width;
	s_view->dotY = s_view->img_height / s_map->height;
	s_view->tile_width = s_view->dotX;
	s_view->tile_height = s_view->dotY;
}

int	*atoiverse(char **str, t_map *s_map)
{
	static int	bool = 1;
	int			*ret;
	int			i;

	i = -1;
	while (str[++i])
		;
	ret = malloc(i * sizeof(int));
	if (!ret)
		quit("Memory allocation failed in the multiverse of atoi");
	i = -1;
	while (str[++i])
		ret[i] = ft_atoi(str[i]);
	if (bool)
	{
		s_map->width = i - 1;
		bool = 0;
	}
	return (ret);
}

void	cartographer(t_map *s_map)
{
	int		fd;
	int		y;
	char	*line;
	char	**splat_line;

	fd = open(s_map->file, O_RDONLY);
	y = 0;
	if (fd == -1)
		quit("Invalid fd");
	s_map->data = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		s_map->data = realloc(s_map->data, (y + 1) * sizeof(int *));
		if (!s_map->data)
			quit("Memory allocation failed >> cartographer");
		splat_line = ft_split(line, ' ');
		s_map->data[y++] = atoiverse(splat_line, s_map);
		free(line);
		line = get_next_line(fd);
	}
	s_map->height = y;
	close(fd);
	free(line);
}
