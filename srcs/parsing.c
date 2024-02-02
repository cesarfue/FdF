/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/02 16:25:22 by cefuente         ###   ########.fr       */
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
	ret = calloc_er(fdf, i, sizeof(int));
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

	fd = open(fdf->map->file, O_RDONLY);
	if (fd == -1)
		quit("Invalid fd");
	y = 0;
	fdf->map->data = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fdf->map->data = ft_realloc(fdf->map->data, y * sizeof(int *),
				(y + 1) * sizeof(int *));
		if (!fdf->map->data)
			quit_app(fdf, 1);
		fdf->map->data[y++] = atoiverse(ft_split(line, ' '), fdf);
		free(line);
		line = get_next_line(fd);
	}
	fdf->map->height = y;
	close(fd);
}
