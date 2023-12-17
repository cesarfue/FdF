/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:58 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/17 13:18:06 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double	deltaX;
// 	double	deltaY;
// 	double	pixelX;
// 	double	pixelY;
// 	int		pixels;
	
// 	deltaX = endX - beginX;
// 	deltaY = endY - beginY;
// 	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// 	deltaX /= pixels;
// 	deltaY /= pixels;
// 	while (pixels)
// 	{
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		pixelX += deltaX;
// 		pixelY += deltaY; 
// 		--pixels;
// 	}
// }

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;
    double pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    deltaX /= pixels;
    deltaY /= pixels;

    double pixelX = beginX; // Initialize pixelX with the starting X coordinate
    double pixelY = beginY; // Initialize pixelY with the starting Y coordinate

    while (pixels)
    {
        // Round to the nearest integer before plotting
        int x = round(pixelX);
        int y = round(pixelY);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }

    return 0;
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_grid(void *mlx, void *win, t_data img, t_view s_view, t_map s_map)
{
    int x_data;
    int y_data;
    int x_draw;
    int y_draw;
    int z;
    int iso_x;
    int iso_y;
    int next_x;
    int next_y;

    y_draw = s_view.margin_y;
    x_draw = s_view.margin_x;

    while (y_draw < s_view.img_height)
    {
        x_data = (y_draw - s_view.margin_y) / s_view.unit_height;
        while (x_draw < s_view.img_width)
        {
            y_data = (x_draw - s_view.margin_x) / s_view.unit_width;

            // Check if the indices are within the bounds of your data array
            if (y_data >= 0 && y_data < s_map.height && x_data >= 0 && x_data < s_map.width)
            {
                z = s_map.data[y_data][x_data];

                iso_x = (sqrt(3) / 2) * (x_draw - y_draw);
                iso_y = (sqrt(3) / 2) * (x_draw + y_draw) - z;

                // Calculate next point only once
                next_x = (sqrt(3) / 2) * (x_draw + 1 - y_draw);
                next_y = (sqrt(3) / 2) * (x_draw + 1 + y_draw) - s_map.data[y_data][x_data + 1];

                // Draw horizontal line if within bounds
                if (x_draw + 1 < s_view.img_width)
                {
                    draw_line(mlx, win, iso_x, iso_y, next_x, next_y, 0xFFFFFF);
                }

                // Calculate next point only once
                next_x = (sqrt(3) / 2) * (x_draw - (y_draw + 1));
                next_y = (sqrt(3) / 2) * (x_draw + (y_draw + 1)) - s_map.data[y_data + 1][x_data];

                // Draw vertical line if within bounds
                if (y_draw + 1 < s_view.img_height)
                {
                    draw_line(mlx, win, iso_x, iso_y, next_x, next_y, 0xFFFFFF);
                }
            }

            x_draw += s_view.unit_width;
        }
        x_draw = s_view.margin_x;
        y_draw += s_view.unit_height;
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
	put_grid(mlx, mlx_win, img, s_view, s_map);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}