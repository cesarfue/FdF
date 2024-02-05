/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/05 18:47:51 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*atoiverse(char **str, t_fdf *fdf)
{
	static int	bool = 1;
	int			*ret;
	int			i;

	i = -1;
	while (str[++i])
		;
	ret = ft_calloc(i, sizeof(int));
	if (!ret)
		return (freetab((void **)str, i), NULL);
	i = -1;
	while (str[++i])
		ret[i] = ft_atoi(str[i]);
	if (bool)
	{
		fdf->map->width = i - 1;
		bool = 0;
	}
	freetab((void **)str, i);
	return (ret);
}

void	cartographer(t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	*rope;

	fd = open(fdf->map->file, O_RDONLY);
	if (fd == -1)
		quit("Invalid fd");
	rope = NULL;
	line = get_next_line(fd, &rope);
	while (line != NULL)
	{
		fdf->map->data = ft_realloc(fdf->map->data,
				fdf->map->height * sizeof(int *),
				(fdf->map->height + 1) * sizeof(int *));
		if (!fdf->map->data)
			return (free(line), free(rope), close(fd), quit_app(fdf, 2));
		fdf->map->data[fdf->map->height] = (int *)
			atoiverse(ft_split(line, ' '), fdf);
		if (!fdf->map->data[fdf->map->height++])
			return (free(line), free(rope), close(fd), quit_app(fdf, 2));
		free(line);
		line = get_next_line(fd, &rope);
	}
	return (close(fd), free(rope), free(line));
}
