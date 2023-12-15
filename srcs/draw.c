/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/15 20:32:35 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_grid(t_data img, t_map s_map)
{
	int	x;
	int	y;
	int Ymax;
	int Xmax;
	int marg;

	Ymax = IMGSIZE_Y;
	Xmax = IMGSIZE_X;
	marg = MARGIN;
	y = marg;
	x = marg;

	while (y < Ymax)
	{
		while (x < Xmax)
		{
			my_mlx_pixel_put(&img, x, y, 0x4EB9B4);
			x++;
		}
		x = marg;
		y += (Ymax / 10);
	}
}

void	draw(t_map s_map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Bruhbadihba");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	put_grid(img, s_map); 
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx); 
}