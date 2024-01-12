/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/12 13:08:40 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
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

void put_grid(void *mlx, void *mlx_win, t_data *img)
{
	(void) img;
    int	i = 0;
	while (i < 500)
	{
		draw_line(mlx, mlx_win, 200 + i, 200, 1200 + i, 1200, 0xFFFFFF); 
		draw_line(mlx, mlx_win, 200, 200 + i, 1200, 1200 + i, 0xFFFFFF); 
		i += 10; 
	}
}

void	draw(t_view s_view, t_map s_map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	(void) s_map; 
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, s_view.win_width,
			s_view.win_height, "Fils de fer");
	img.img = mlx_new_image(mlx, s_view.win_width, s_view.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	put_grid(mlx, mlx_win, &img);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}