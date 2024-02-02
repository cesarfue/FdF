/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:58 by cesar             #+#    #+#             */
/*   Updated: 2024/02/02 14:53:11 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	new_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->img->mlx, fdf->img->img);
	fdf->img->img = mlx_new_image(fdf->img->mlx,
			fdf->opts->win_width, fdf->opts->win_height);
	if (!fdf->img->img)
		quit_app(fdf, -1);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel,
			&fdf->img->line_length, &fdf->img->endian);
	if (!fdf->img->addr)
		quit_app(fdf, -1);
	positions(fdf);
	is_that_bob_ross(fdf);
}

int	escaped(int key)
{
	if (key == 65307)
		return (1);
	return (0);
}

int	view_changed(int key, t_fdf *fdf)
{
	if (key == 65363)
		return (fdf->opts->view_x -= 80, 1);
	if (key == 65361)
		return (fdf->opts->view_x += 80, 1);
	if (key == 65364)
		return (fdf->opts->view_y -= 80, 1);
	if (key == 65362)
		return (fdf->opts->view_y += 80, 1);
	if (key == 45)
		return (fdf->opts->scale -= 0.05, 1);
	if (key == 61)
		return (fdf->opts->scale += 0.05, 1);
	if (key == 32)
		return (fdf->opts->angle += 0.05, 1);
	if (key == 65289)
		return (fdf->opts->angle -= 0.05, 1);
	if (key == 49)
		return (fdf->opts->alt_scale -= 1, 1);
	if (key == 50)
		return (fdf->opts->alt_scale += 1, 1);
	if (key == 113)
		return (fdf->opts->rotate -= 0.05, 1);
	if (key == 119)
		return (fdf->opts->rotate += 0.05, 1);
	return (0);
}

int	key_events(int key, t_fdf *fdf)
{
	if (view_changed(key, fdf) == 1)
		new_image(fdf);
	else if (escaped(key) == 1)
		quit_app(fdf, 0);
	return (0);
}
