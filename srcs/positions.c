/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:00:49 by cesar             #+#    #+#             */
/*   Updated: 2024/01/31 17:53:33 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso(t_pos *pos, t_opts *opts)
{
	pos->x = (pos->x - pos->y) * cos(opts->angle);
	pos->y = (pos->x + pos->y) * sin(opts->angle) - pos->z;
	pos->x += opts->view_x;
	pos->y += opts->view_y;
}

void	calc_min_max(t_pos pos, t_opts *opts)
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
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			base_pos(&fdf->pos[y][x], fdf, y, x);
			iso(&fdf->pos[y][x], fdf->opts);
			calc_min_max(fdf->pos[y][x], fdf->opts);
			x++;
		}
		x = 0;
		y++;
	}
}
