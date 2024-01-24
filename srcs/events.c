/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:58 by cesar             #+#    #+#             */
/*   Updated: 2024/01/23 16:01:38 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_events(int key, t_fdf *fdf)
{
	if (key == 113)
		fdf->opts->view_x -= 80;
	if (key == 114)
		 fdf->opts->view_x += 80;
	if (key == 111)
		fdf->opts->view_y -= 80;
	if (key == 116)
		fdf->opts->view_y += 80;
	mlx_destroy_image(fdf->img->mlx, fdf->img->img);
	mlx_clear_window(fdf->img->mlx, fdf->img->mlx_win);
	// fdf->img->img = mlx_new_image(fdf->img->mlx, 2000, 2000);
	// if (!fdf->img->img)
	// 	quit("mlx failed in key hook.c");
	// fdf->img->addr = mlx_get_data_addr(fdf->img->img, 
	// &fdf->img->bits_per_pixel, 
	// &fdf->img->line_length, &fdf->img->endian);
	// init_mlx(fdf);
	positions(fdf);
	is_that_bob_ross(fdf);
	return (0);
}



