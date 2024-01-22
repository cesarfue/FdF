/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/22 16:42:52 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>



void	px_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int line(t_opts *opts, t_img *img, t_pos pos, t_pos npos)
{
	float	delta_x;
	float	delta_y;
	float		px;
	float		i;
	
	delta_x = npos.x - pos.x;
	delta_y = npos.y - pos.y;
	px = max(absol(delta_x), absol(delta_y));
	delta_x /= px;
	delta_y /= px;
	i = 0;
	while ((int)(pos.x - npos.x) || (int)(pos.y - npos.y))
	{
		if (pos.x > opts->win_width || pos.y > opts->win_height || pos.y < 0 || pos.x < 0)
			break ;
		gradient(&pos, &npos, i, px);
		px_put(img, pos.x, pos.y, pos.color);
		pos.x += delta_x;
		pos.y += delta_y;
		i++;
	}
	return (0);
}

void is_that_bob_ross(t_fdf *fdf, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->map->height - 1)
	{
		while (x < fdf->map->width - 1)
		{
			line(fdf->opts, img, fdf->pos[y][x], fdf->pos[y][x + 1]);
			line(fdf->opts, img, fdf->pos[y][x], fdf->pos[y + 1][x]);
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_mlx(t_fdf *fdf)
{
	void	*mlx;
	void	*mlx_win;

	t_img	img;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, fdf->opts->win_width,
			fdf->opts->win_height, "Fils de fer");
	img.img = mlx_new_image(mlx, fdf->opts->win_width, fdf->opts->win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	is_that_bob_ross(fdf, &img);
	// mlx_key_hook(mlx_win, key_events, &fdf->opts);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}