/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/12 19:25:36 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int draw_line(void *mlx, void *mlx_win, int beginX, int beginY, int endX, int endY, int color)
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
		mlx_pixel_put(mlx, mlx_win, pixelX, pixelY, color); 
		pixelX += deltaX;
		pixelY += deltaY; 
		--pixels;
	}
	return (0);
}

void	to_iso(int *iso_x, int *iso_y, t_view *s_view, t_map *s_map, int xI, int yI)
{
	int x;
	int	y;

	x = *iso_x;
	y = *iso_y;
	if (xI >= 0 && xI < s_map->width && yI >= 0 && yI < s_map->height)
	{
		*iso_x = (x - y) * s_view->tile_width / 2;
		*iso_y = (x + y) * s_view->tile_height / 2 - s_view->alt_scale * s_map->data[yI][xI];
	}
	else
		quit("Out-of bound error while converting to iso");
}

void put_grid(void *mlx, void *mlx_win, t_map *s_map, t_view *s_view)
{
	int	x;
	int	y;
	int	xI;
	int	yI;
	int iso_x;
	int	iso_y;

	x = s_view->margin_x;
	y = s_view->margin_y; 
	xI = 0;
	yI = 0;
	while (yI < s_map->height)
	{
		while (xI < s_map->width)
		{
			iso_x = x;
			iso_y = y;
			// to_iso(&iso_x, &iso_y, s_view, s_map, xI, yI);
			draw_line(mlx, mlx_win, iso_x, iso_y, iso_x, iso_y + s_view->dotY, 0xFFFFFF);
			draw_line(mlx, mlx_win, iso_x, iso_y, iso_x + s_view->dotX, iso_y, 0xFFFFFF);
			x += s_view->dotX;
			xI++;
		}
		x = s_view->margin_x;
		y += s_view->dotY;
		xI = 0;
		yI++;
	}
}

void	draw(t_view s_view, t_map s_map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, s_view.win_width,
			s_view.win_height, "Fils de fer");
	img.img = mlx_new_image(mlx, s_view.win_width, s_view.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	put_grid(mlx, mlx_win, &s_map, &s_view);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}