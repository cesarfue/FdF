/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:00:49 by cesar             #+#    #+#             */
/*   Updated: 2024/02/01 18:13:33 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso(t_pos *pos, t_opts *opts)
{
	float	prev_x;
	float	prev_y;

	prev_x = pos->x;
	prev_y = pos->y;
	pos->x = prev_x * cos(opts->rotate) - prev_y * sin(opts->rotate);
	pos->y = prev_x * sin(opts->rotate) + prev_y * cos(opts->rotate);
	pos->x = (pos->x - pos->y) * cos(opts->angle);
	pos->y = (pos->x + pos->y) * sin(opts->angle) - pos->z;
	pos->x += opts->view_x;
	pos->y += opts->view_y;
}

void	calc_zmin_zmax(t_pos pos, t_opts *opts)
{
	if (pos.z < opts->min_z)
		opts->min_z = pos.z;
	if (pos.z > opts->max_z)
		opts->max_z = pos.z;
}

void	base_pos(t_pos *pos, t_fdf *fdf, int y, int x)
{
	pos->y = y * fdf->opts->step * fdf->opts->scale;
	pos->x = x * fdf->opts->step * fdf->opts->scale;
	pos->z = fdf->map->data[y][x] * fdf->opts->alt_scale * fdf->opts->scale;
}

void	positions(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	fdf->opts->min_z = __FLT_MAX__;
	fdf->opts->max_z = __FLT_MIN__;
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			base_pos(&fdf->pos[y][x], fdf, y, x);
			iso(&fdf->pos[y][x], fdf->opts);
			calc_zmin_zmax(fdf->pos[y][x], fdf->opts);
			x++;
		}
		x = 0;
		y++;
	}
}
