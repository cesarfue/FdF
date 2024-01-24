/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/23 15:50:26 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_opts(t_fdf *fdf)
{
	fdf->opts->win_width = WIN_WIDTH;
	fdf->opts->win_height = WIN_HEIGHT;
	fdf->opts->view_x = 0;
	fdf->opts->view_y = 0; 
	fdf->opts->angle = 0.8;
	fdf->opts->scale = 1;
	fdf->opts->alt_scale = 5;
	fdf->opts->img_width = fdf->opts->win_width * fdf->opts->scale;
	fdf->opts->img_height = fdf->opts->win_height * fdf->opts->scale;
	fdf->opts->step = fdf->opts->img_width / fdf->map->width;
	fdf->opts->first_time = 1;
	fdf->opts->min_x = __FLT_MAX__;
	fdf->opts->max_x = __FLT_MIN__;
	fdf->opts->min_y = __FLT_MAX__;
	fdf->opts->max_y = __FLT_MIN__;
	fdf->opts->min_z = __INT_MAX__;
	fdf->opts->max_z = INT_MIN;
	alloc_positions(fdf);
}

void	init_mlx(t_fdf *fdf)
{
	fdf->img->mlx = mlx_init();
	fdf->img->mlx_win = mlx_new_window(fdf->img->mlx, fdf->opts->win_width,
			fdf->opts->win_height, "Fils de fer");
	fdf->img->img = mlx_new_image(fdf->img->mlx, fdf->opts->win_width, fdf->opts->win_height);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel,
			&fdf->img->line_length, &fdf->img->endian);
	is_that_bob_ross(fdf);
	mlx_hook(fdf->img->mlx_win, 2, 0, key_events, fdf);
	mlx_loop(fdf->img->mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	
	if (!argv[0] || !argv[1] || (argc != 2))
		quit("Invalid arguments");
	fdf.img = malloc(sizeof(t_img));
	fdf.map = malloc(sizeof(t_map));
	fdf.opts = malloc(sizeof(t_opts));
	fdf.map->file = argv[1];
	cartographer(&fdf);
	init_opts(&fdf);
	positions(&fdf);
	init_mlx(&fdf);

	return (0);
}