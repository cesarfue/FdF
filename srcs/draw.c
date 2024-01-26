/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/26 15:12:28 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	px_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	iso(t_pos *pos, float angle)
{
	pos->x = (pos->x - pos->y) * cos(angle);
	pos->y = (pos->x + pos->y) * sin(angle) - pos->z;
}

int	line(t_opts *opts, t_img *img, t_pos pos, t_pos npos)
{
	float	delta_x;
	float	delta_y;
	float	px;
	float	i;

	delta_x = npos.x - pos.x;
	delta_y = npos.y - pos.y;
	px = max(absol(delta_x), absol(delta_y));
	delta_x /= px;
	delta_y /= px;
	i = 0;
	while ((int)(pos.x - npos.x) || (int)(pos.y - npos.y))
	{
		if (pos.x > opts->win_width || pos.y > opts->win_height
			|| pos.y < 0 || pos.x < 0)
			break ;
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
}
