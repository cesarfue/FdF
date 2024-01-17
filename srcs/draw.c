/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/17 15:40:58 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_dot *dot)
{
	dot->x = (dot->x - dot->y) * cos(0.5);
	dot->y = (dot->x + dot->y) * sin(0.5) - dot->z;
}

void	px_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int line(t_img *img, t_dot a, t_dot b, int color)
{
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;
	int		pixels;
	
	deltaX = b.x - a.x;
	deltaY = b.y - a.y;
	pixelX = a.x;
	pixelY = a.y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		px_put(img, pixelX, pixelY, color); 
		pixelX += deltaX;
		pixelY += deltaY; 
		--pixels;
	}
	return (0);
}

void is_that_bob_ross(t_fdf *fdf, t_img *img)
{
	int	x;
	int	y;
	int	xI;
	int	yI;

	x = fdf->opts->margin_x;
	y = fdf->opts->margin_y;
	xI = 0;
	yI = 0;
	while (yI < fdf->map->height)
	{
		while (xI < fdf->map->width)
		{
			ft_printf("a.x is %d, b.x is %d\n", dot[yI][xI], b.x);
			line(img, fdf->dot[yI][xI], fdf->dot[yI][xI + 1], 0xFFFFFF);
			line(img, fdf->dot[yI][xI], fdf->dot[yI + 1][xI], 0xFFFFFF);
			x += fdf->opts->dotX;
			xI++;
		}
		x = fdf->opts->margin_x;
		y += fdf->opts->dotY;
		xI = 0;
		yI++;
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