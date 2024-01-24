/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:00:49 by cesar             #+#    #+#             */
/*   Updated: 2024/01/23 15:52:46 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calc_min_max(t_pos pos, t_opts *opts)
{
	if (pos.x < opts->min_x)
		opts->min_x = pos.x;
	if (pos.x > opts->max_x)
		opts->max_x = pos.x;
	if (pos.y < opts->min_y)
		opts->min_y = pos.y;
	if (pos.y > opts->max_y)
		opts->max_y = pos.y;
	if (pos.z < opts->min_z)
		opts->min_z = pos.z;
	if (pos.z > opts->max_z)
		opts->max_z = pos.z;
}

void	adjust(t_fdf *fdf)
{
	if (fdf->opts->first_time == 0)
		return ;
	fdf->opts->view_y += absol(fdf->opts->min_y);
	fdf->opts->view_x += absol(fdf->opts->min_x);
	fdf->opts->first_time = 0;
	positions(fdf);
}

void	scale(t_opts *opts, t_pos *pos)
{
	if (opts->first_time == 1)
		return ;
	pos->y += opts->view_y;
	pos->x += opts->view_x;
}

void	base_pos(t_pos *pos, t_opts *opts, t_map *map, int y, int x)
{
	pos->y = y * opts->step;
	pos->x = x * opts->step;
	pos->z = map->data[y][x] * opts->alt_scale;
}

void	positions(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < fdf->map->height) 				
	{
		while (x < fdf->map->width)
		{
			base_pos(&fdf->pos[y][x], fdf->opts, fdf->map, y, x);
			iso(&fdf->pos[y][x], fdf->opts->angle);
			scale(fdf->opts, &fdf->pos[y][x]);
			colors(fdf->opts, &fdf->pos[y][x]);
			calc_min_max(fdf->pos[y][x], fdf->opts);
			x++;
		}
		x = 0;
		y++;
	}
	adjust(fdf);
}
