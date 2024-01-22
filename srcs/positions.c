/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:00:49 by cesar             #+#    #+#             */
/*   Updated: 2024/01/22 16:23:32 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	define_view(t_fdf *fdf)
{
	fdf->opts->win_width = WIN_WIDTH;
	fdf->opts->win_height = WIN_HEIGHT;
	fdf->opts->angle = ANGLE;
	fdf->opts->alt_scale = ALT_SCALE;
	fdf->opts->img_width = fdf->opts->win_width * SCALE;
	fdf->opts->img_height = fdf->opts->win_height * SCALE;
	fdf->opts->step = fdf->opts->img_width / fdf->map->width;
	fdf->opts->view_x = VIEW_X;
	fdf->opts->view_y = VIEW_Y; 
}

void	iso(t_pos *pos, float angle) 			/* Isometric conversion */
{
	pos->x = (pos->x - pos->y) * cos(angle);
	pos->y = (pos->x + pos->y) * sin(angle) - pos->z;
}

void	positions(t_fdf *fdf)				/* Calculates default isometric positions and calls scale functions*/
{
	int	y;
	int	x;

	fdf->opts->min_x = __FLT_MAX__;
	fdf->opts->max_x = __FLT_MIN__;
	fdf->opts->min_y = __FLT_MAX__;
	fdf->opts->max_y = __FLT_MIN__;
	fdf->opts->min_z = __INT_MAX__;
	fdf->opts->max_z = 0;
	y = 0;
	x = 0;
	alloc_positions(fdf);
	while (y < fdf->map->height) 				
	{
		while (x < fdf->map->width)
		{
			fdf->pos[y][x].y = y * fdf->opts->step;
			fdf->pos[y][x].x = x * fdf->opts->step;
			fdf->pos[y][x].z = fdf->map->data[y][x] * fdf->opts->alt_scale;
			iso(&fdf->pos[y][x], fdf->opts->angle);
			calc_min_max(fdf->pos[y][x], fdf->opts);
			x++;
		}
		x = 0;
		y++;
	}
	scale_positions(fdf);
}
