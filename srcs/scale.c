/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:53:19 by cesar             #+#    #+#             */
/*   Updated: 2024/01/22 15:15:06 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calc_min_max(t_pos pos, t_opts *opts) 	/* Keeps track of min and max positions so they can be centered later */
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

void scale_positions(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			fdf->pos[y][x].y = y * fdf->opts->step;
			fdf->pos[y][x].x = x * fdf->opts->step;
			fdf->pos[y][x].z = fdf->map->data[y][x] * fdf->opts->alt_scale;
			iso(&fdf->pos[y][x], fdf->opts->angle);
			fdf->pos[y][x].x += absol(fdf->opts->min_x) + VIEW_X; 
			fdf->pos[y][x].y += absol(fdf->opts->min_y) + VIEW_Y;
			colors(fdf->opts, &fdf->pos[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}