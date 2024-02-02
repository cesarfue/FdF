/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:35 by cesar             #+#    #+#             */
/*   Updated: 2024/02/02 15:15:56 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	absol(float i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

float	max(float x, float y)
{
	if (x >= y)
		return (x);
	return (y);
}

void	alloc_positions(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->pos = malloc_er((fdf->map->height) * sizeof(t_pos *));
	while (i < fdf->map->height)
	{
		fdf->pos[i] = malloc_er((fdf->map->width) * sizeof(t_pos));
		i++;
	}
}

void	quit_app(t_fdf *fdf, int err)
{
	if (fdf->img->mlx && fdf->img->mlx_win)
		mlx_destroy_image(fdf->img->mlx, fdf->img->img);
	if (fdf->img->mlx && fdf->img->mlx_win)
		mlx_destroy_window(fdf->img->mlx, fdf->img->mlx_win);
	if (fdf->img->mlx)
		mlx_destroy_display(fdf->img->mlx);
	freetab_ext((void **)fdf->map->data, fdf->map->height);
	freetab_in((void **)fdf->pos, fdf->map->height);
	free(fdf->map);
	free(fdf->pos);
	free(fdf->opts);
	free(fdf->img->mlx);
	free(fdf->img);
	free(fdf);
	if (err == -1)
		quit("An error occurred inside mlx functions");
	else
		exit(0);
}
