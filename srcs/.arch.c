/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .arch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 07:23:48 by cesar             #+#    #+#             */
/*   Updated: 2024/01/18 14:25:04 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// void	to_iso(int x, int y, int xI, int yI, int *iso_x, int *iso_y, t_map *s_map)
// {
// 	int z;

// 	z = s_map->data[yI][xI];
// 	// *iso_x = (x - z) / sqrt(2);
// 	// *iso_y = (x + (2 * y) + z) / sqrt(6);
// 	*iso_x = (x - y) * cos(30);
// 	*iso_y = (x + y) * sin(30) - z;
// }


// void	def_dot(t_fdf *fdf)
// {
// 	int	i;
// 	int	y;
// 	int	x;

// 	i = 0;
// 	y = 0;
// 	x = 0;
// 	fdf->dot = malloc(fdf->map->height * sizeof(t_pos *));
// 	while (i < fdf->map->height)
// 		fdf->dot[i++] = malloc(fdf->map->width * sizeof(t_pos));
// 	while (y < fdf->map->height)
// 	{
// 		while (x < fdf->map->width)
// 		{
// 			fdf->dot[y][x].y = y;
// 			fdf->dot[y][x].x = x;
// 			fdf->dot[y][x].z = fdf->map->data[y][x]; 
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }