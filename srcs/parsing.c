/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/15 17:51:05 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**parsing(char *file)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(file, O_RDONLY);
	i = 0;
	if (!fd)
		quit("Invalid fd");
	map = malloc (2 * sizeof(char)); 
	if (!map)
		quit("");
	while (fd)
	{
		map[i] = get_next_line(fd); 
		ft_printf("%s", map[i]);
		i++;
	}
	return (map); 
}