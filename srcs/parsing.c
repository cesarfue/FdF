/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/31 15:11:08 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	*atoiverse(char **str, t_fdf *fdf)
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
		fdf->map->width = i - 1;
		bool = 0;
	}
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (ret);
}

void	cartographer(t_fdf *fdf)
{
	int		fd;
	int		y;
	char	*line;
	char	**splat_line;

	fd = open(fdf->map->file, O_RDONLY);
	y = 0;
	if (fd == -1)
		quit("Invalid fd");
	fdf->map->data = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fdf->map->data = ft_realloc(fdf->map->data, y * sizeof(int *), (y + 1) * sizeof(int *));
		if (!fdf->map->data)
			quit("Memory allocation failed >> cartographer");
		splat_line = ft_split(line, ' ');
		fdf->map->data[y++] = atoiverse(splat_line, fdf);
		free(line);
		line = get_next_line(fd);
	}
	fdf->map->height = y;
	close(fd);
	free(line);
}
