/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/16 20:57:37 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	def_view(t_view *s_view)
{
	s_view->win_width = WIN_WIDTH;
	s_view->win_height = WIN_HEIGHT;
	s_view->img_width = s_view->win_width * 0.7;
	s_view->img_height = s_view->win_height * 0.7;
	s_view->margin_x = s_view->win_width * 0.3;
	s_view->margin_y = s_view->win_height * 0.3;
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
	s_map->content = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		s_map->content = realloc(s_map->content, (y + 1) * sizeof(int *));
		if (!s_map->content)
			quit("Memory allocation failed >> cartographer");
		splat_line = ft_split(line, ' ');
		s_map->content[y++] = atoiverse(splat_line, s_map);
		free(line);
		line = get_next_line(fd);
	}
	s_map->height = y;
	close(fd);
	free(line);
}
