/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:53:19 by cesar             #+#    #+#             */
/*   Updated: 2024/01/19 18:08:07 by cesar            ###   ########.fr       */
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

// void	define_scale(t_fdf *fdf)
// {
// 	float	range_x;

// 	range_x = fdf->opts->max_x - fdf->opts->min_x;
// 	fdf->opts->scale_factor = fdf->opts->img_width / range_x;
// 	fdf->opts->scaled_step = fdf->opts->step * fdf->opts->scale_factor;
// 	fdf->opts->height_offset = (fdf->opts->img_height - (fdf->opts->max_y - fdf->opts->min_y)) / 2;
// }	

void	colors(t_opts *opts, t_pos *pos)
{
	float	range;
	float	sector;

	range = opts->max_z - opts->min_z;
	sector = range / 5;

	if (pos->z >= opts->min_z && pos->z < opts->min_z + sector)
		pos->color = 0xffccff;
	else if (pos->z >= opts->min_z + sector && pos->z < opts->min_z + sector * 2)
		pos->color = 0xccccff;
	else if (pos->z >= opts->min_z + sector * 2 && pos->z < opts->min_z + sector * 3)
		pos->color = 0x99ccff;
	else if (pos->z >= opts->min_z + sector * 3 && pos->z < opts->min_z + sector * 4)
		pos->color = 0x666699;
	else if (pos->z >= opts->min_z + sector * 4 )
		pos->color = 0x333366;
}

void scale_positions(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	// define_scale(fdf);
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			// iso(&fdf->pos[y][x], fdf->opts->angle);
			// fdf->pos[y][x].x += absol(fdf->opts->min_x);
			// fdf->pos[y][x].y += fdf->opts->height_offset;
			fdf->pos[y][x].y = y * fdf->opts->step;
			fdf->pos[y][x].x = x * fdf->opts->step;
			fdf->pos[y][x].z = fdf->map->data[y][x] * fdf->opts->alt_scale;
			iso(&fdf->pos[y][x], fdf->opts->angle);
			fdf->pos[y][x].x += absol(fdf->opts->min_x) + 300; 
			fdf->pos[y][x].y += absol(fdf->opts->min_y) + 500;
			// colors(fdf->opts, &fdf->pos[y][x]);
			
			x++;
		}
		x = 0;
		y++;
	}
}