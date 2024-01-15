/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/15 15:50:50 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	to_iso(t_map *s_map)
// {
// 	int	xI;
// 	int	yI;
// 	while (xI < s_map->wid)
// }

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

// void	to_iso(int *iso_x, int *iso_y, t_view *s_view, t_map *s_map, int xI, int yI)
// {
// 	// int x;
// 	// int	y;

// 	// x = *iso_x;
// 	// y = *iso_y;
// 	if (xI >= 0 && xI < s_map->width && yI >= 0 && yI < s_map->height)
// 	{
// 		ft_printf("*iso_x = (%d - %d) * %d = %d\n*iso_y = (%d + %d) * %d - %d * %d = %d\n", xI, yI, s_view->tile_width / 2, (xI - yI) * s_view->tile_width / 2, xI, yI, s_view->tile_height / 2, s_view->alt_scale, s_map->data[yI][xI], (xI + yI) * s_view->tile_height / 2 - s_view->alt_scale * s_map->data[yI][xI]);
// 		*iso_x = (xI - yI) * s_view->tile_width / 2;
// 		*iso_y = (xI + yI) * s_view->tile_height / 2 - s_view->alt_scale * s_map->data[yI][xI];
// 	}
// 	else
// 		quit("Out-of bound error while converting to iso");
// }

void	to_iso(int x, int y, int xI, int yI, int *iso_x, int *iso_y, t_map *s_map)
{
	int z;

	z = s_map->data[yI][xI];
	*iso_x = (x - z) / sqrt(2);
	*iso_y = (x + (2 * y) + z) / sqrt(6);
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
			to_iso(x, y, xI, yI, &iso_x, &iso_y, s_map);
			ft_printf("iso_x = %d || iso_y = %d || iso_x + s_view->dotX = %d || iso_y + s_view->dotY = %d\n", iso_x, iso_y, iso_x + s_view->dotX, iso_y + s_view->dotY);
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
	convert_map(&s_map);
	put_grid(mlx, mlx_win, &s_map, &s_view);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}