/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/17 15:39:05 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	def_dot(t_fdf *fdf)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	fdf->dot = malloc(fdf->map->height * sizeof(t_dot *));
	while (i < fdf->map->height)
		fdf->dot[i++] = malloc(fdf->map->width * sizeof(t_dot));
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			fdf->dot[y][x].y = y;
			fdf->dot[y][x].x = x;
			fdf->dot[y][x].z = fdf->map->data[y][x]; 
			// ft_printf("dot[%d][%d] = %d\n", fdf->dot[y][x].y, fdf->dot[y][x].x, fdf->dot[y][x].z);
			x++;
		}
		x = 0;
		y++;
	}
}

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
		fdf->map->data = realloc(fdf->map->data, (y + 1) * sizeof(int *));
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
	def_dot(fdf);
}
