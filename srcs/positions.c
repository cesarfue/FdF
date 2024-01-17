/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:00:49 by cesar             #+#    #+#             */
/*   Updated: 2024/01/17 18:16:39 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	def_view(t_fdf *fdf)
{
	fdf->opts->win_width = WIN_WIDTH;
	fdf->opts->win_height = WIN_HEIGHT;
	fdf->opts->img_width = fdf->opts->win_width * SCALE;
	fdf->opts->img_height = fdf->opts->win_height * SCALE;
	fdf->opts->margin_x = fdf->opts->win_width * 0.2;
	fdf->opts->margin_y = fdf->opts->win_height * 0.2;
	fdf->opts->dotX = fdf->opts->img_width / fdf->map->width;
	fdf->opts->dotY = fdf->opts->img_height / fdf->map->height;
	fdf->opts->angle = 0.5239;
}

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
			x++;
		}
		x = 0;
		y++;
	}
}
void	def_pos(t_fdf *fdf)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	fdf->pos = malloc(fdf->map->height * sizeof(t_dot *));
	while (i < fdf->map->height)
		fdf->pos[i++] = malloc(fdf->map->width * sizeof(t_dot));
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			fdf->pos[y][x].y = y * fdf->opts->dotY + fdf->opts->margin_y;
			fdf->pos[y][x].x = x * fdf->opts->dotX + fdf->opts->margin_x;
			fdf->pos[y][x].z = fdf->map->data[y][x]; 
			x++;
		}
		x = 0;
		y++;
	}
}

void	positions(t_fdf *fdf)
{
	def_view(fdf);
	def_dot(fdf);
	def_pos(fdf);
}