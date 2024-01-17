/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/16 10:54:13 by cesar            ###   ########.fr       */
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

int line(t_fdf *fdf, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;
	int		pixels;
	
	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixelX = beginX;
	pixelY = beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		px_put(fdf->img, pixelX, pixelY, color); 
		pixelX += deltaX;
		pixelY += deltaY; 
		--pixels;
	}
	return (0);
}

// void	line(t_dot a, t_dot b, t_dot *param)
// {
// 	float	step_x;
// 	float	step_y;
// 	float	max;
// 	int		color;

// 	// set_param(&a, &b, param);
// 	isometric(a, b);
// 	step_x = b.x - a.x;
// 	step_y = b.y - a.y;
// 	// max = maxim(fmodule(step_x), fmodule(step_y));
// 	step_x /= max;
// 	step_y /= max;
// 	color = set_color(b.z, a.z);
// 	while ((int)(a.x - b.x) || (int)(a.y - b.y))
// 	{
// 		px_put(param, a.x, a.y, color);
// 		a.x += step_x;
// 		a.y += step_y;
// 		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
// 			break ;
// 	}
// }

void is_that_bob_ross(t_fdf *fdf)
{
	int	x;
	int	y;
	int	xI;
	int	yI;
	int iso_x;
	int	iso_y;

	x = fdf->opts->margin_x;
	y = fdf->opts->margin_y; 
	xI = 0;
	yI = 0;
	while (yI < fdf->map->height)
	{
		while (xI < fdf->map->width)
		{
			line(fdf->dot[y][x], fdf->dot[y][x + 1])
			x += fdf->opts->dotX;
			xI++;
		}
		x = fdf->opts->margin_x;
		y += fdf->opts->dotY;
		xI = 0;
		yI++;
	}
}

void	init_mlx(t_fdf fdf)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, fdf.opts.win_width,
			fdf.opts.win_height, "Fils de fer");
	fdf.img = mlx_new_image(mlx, fdf.opts.win_width, fdf.opts.win_height);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel,
			&fdf.img.line_length, &fdf.img.endian);
	is_that_bob_ross(&fdf);
	mlx_put_image_to_window(mlx, mlx_win, fdf.img.img, 0, 0);
	mlx_loop(mlx);
}