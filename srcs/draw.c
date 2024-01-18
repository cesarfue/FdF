/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/18 15:57:59 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

float	absol(float i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

float	max(float x, float y)
{
	if (x >= y)
		return (x);
	return (y);
}

void	px_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int line(t_opts *opts, t_img *img, t_pos pos, t_pos npos, int color)
{
	float	delta_x;
	float	delta_y;
	float		px;
	
	delta_x = npos.x - pos.x;
	delta_y = npos.y - pos.y;
	printf("pos.x = %f, npos.x = %f || pos.y = %f, npos.y = %f\n", pos.x, npos.x, pos.y, npos.y);
	px = max(absol(delta_x), absol(delta_y));
	delta_x /= px;
	delta_y /= px;
	while ((int)(pos.x - npos.x) || (int)(pos.y - npos.y))
	{
		px_put(img, pos.x, pos.y, color);
		pos.x += delta_x;
		pos.y += delta_y;
		// if (pos.x > opts->img_width || pos.y > opts->img_height || pos.y < 0 || pos.x < 0)
		// 	break ;
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
			line(fdf->opts, img, fdf->pos[y][x], fdf->pos[y][x + 1], 0xFFFFFF);
			line(fdf->opts, img, fdf->pos[y][x], fdf->pos[y + 1][x], 0xFFFFFF);
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}