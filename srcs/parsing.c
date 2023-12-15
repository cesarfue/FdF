/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/15 19:28:48 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	parsing(t_map s_map)
{
	int		fd;
	int		y;
	int		x;
	char	**map;
	char	*line;

	fd = open(s_map.file, O_RDONLY);
	y = 0;
	x = 0;
	if (fd == -1)
		quit("Invalid fd");
	s_map.content = malloc (100 * sizeof(char*)); 
	if (!s_map.content)
		free(s_map.content), quit("");
	while ((line = get_next_line(fd)) != NULL)
	{
		s_map.content[y] = line; 
		ft_printf("%s", s_map.content[y]);
		y++;
	}
	s_map.y = y;
	y = 0;
	while (s_map.content[y][x] != '\n')
		x++;
	s_map.x = x;
	ft_printf("y is %d, x is %d\n", s_map.y, s_map.y);
	close(fd);
	free(line); 
	return (s_map); 
}