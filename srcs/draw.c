/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/31 21:35:50 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	px_put(t_img *img, int x, int y, int color)
{
	char	*dst;
 
	if (x >= WIN_WIDTH || x <= 0 || y >= WIN_HEIGHT || y <= 0)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	line(t_opts *opts, t_img *img, t_pos pos, t_pos npos)
{
	float	delta_x;
	float	delta_y;
	float	px;
	float	i;

	colors(opts, &pos);
	colors(opts, &npos);
	delta_x = npos.x - pos.x;
	delta_y = npos.y - pos.y;
	px = max(absol(delta_x), absol(delta_y));
	delta_x /= px;
	delta_y /= px;
	i = 0;
	while ((int)(pos.x - npos.x) || (int)(pos.y - npos.y))
	{
		gradient(&pos, &npos, i, px);
		px_put(img, pos.x, pos.y, pos.color);
		pos.x += delta_x;
		pos.y += delta_y;
		i++;
	}
	return (0);
}

void	is_that_bob_ross(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	fdf->opts->range = fdf->opts->max_z - fdf->opts->min_z;
	fdf->opts->sector = fdf->opts->range / 3;
	while (y < fdf->map->height)
	{
		while (x < fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				line(fdf->opts, fdf->img, fdf->pos[y][x], fdf->pos[y][x + 1]);
			if (y + 1 < fdf->map->height)
				line(fdf->opts, fdf->img, fdf->pos[y][x], fdf->pos[y + 1][x]);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fdf->img->mlx, fdf->img->mlx_win,
		fdf->img->img, 0, 0);
	menu(fdf->img, fdf->opts);
}
