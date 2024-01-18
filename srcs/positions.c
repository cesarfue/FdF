/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:00:49 by cesar             #+#    #+#             */
/*   Updated: 2024/01/18 15:57:46 by cesar            ###   ########.fr       */
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
	fdf->opts->angle = 0.645;
	fdf->opts->alt_scale = 5;
}
void	iso(t_pos *pos, float angle)
{
	pos->x = (pos->x - pos->y) * cos(angle);
	pos->y = (pos->x + pos->y) * sin(angle) - pos->z;
}

// void	projection(t_opts *opts, t_pos *pos)
// {
// 	(void)opts;
// 	// if (pos->x < mi4n_x)
// 	// 	min_x = pos->x;
// 	iso(pos);
// }

void	def_pos(t_fdf *fdf)
{
	int	y;
	int	x;
	// float	min_x;
	// float	max_x;

	y = 0;
	x = 0;
	// min_x = __FLT_MAX__;
	// max_x = __FLT_MIN__;
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			fdf->pos[y][x].y = y * fdf->opts->dotY;
			fdf->pos[y][x].x = x * fdf->opts->dotX + 1500;
			fdf->pos[y][x].z = fdf->map->data[y][x] * fdf->opts->alt_scale;
			iso(&fdf->pos[y][x], fdf->opts->angle);
			// projection(fdf->opts, &fdf->pos[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}

void alloc_pos(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->pos = malloc(fdf->map->height * sizeof(t_pos *));
	if (!fdf->pos)
		quit("alloc faild -> pos");
	while (i < fdf->map->height)
	{
		fdf->pos[i] = malloc(fdf->map->width * sizeof(t_pos));
		if (!fdf->pos[i])
			quit("alloc faild -> pos");
		i++;
	}
}


void	positions(t_fdf *fdf)
{
	def_view(fdf);
	alloc_pos(fdf);
	def_pos(fdf);
}