/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/07 13:29:02 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_opts(t_fdf *fdf)
{
	fdf->opts->win_width = WIN_WIDTH;
	fdf->opts->win_height = WIN_HEIGHT;
	fdf->opts->view_x = 500;
	fdf->opts->view_y = 0;
	fdf->opts->angle = 0.8;
	fdf->opts->scale = 1;
	fdf->opts->alt_scale = 5;
	fdf->opts->loops = 0;
	fdf->opts->rotate = 0;
	if (fdf->map->width > 0)
		fdf->opts->step = fdf->opts->win_width / fdf->map->width;
}

void	init_mlx(t_fdf *fdf)
{
	fdf->img->mlx = mlx_init();
	if (!fdf->img->mlx)
		quit_app(fdf, 4);
	fdf->img->mlx_win = mlx_new_window(fdf->img->mlx, fdf->opts->win_width,
			fdf->opts->win_height, "Fils de fer");
	if (!fdf->img->mlx_win)
		quit_app(fdf, 5);
	fdf->img->img = mlx_new_image(fdf->img->mlx,
			fdf->opts->win_width, fdf->opts->win_height);
	if (!fdf->img->img)
		quit_app(fdf, 6);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel,
			&fdf->img->line_length, &fdf->img->endian);
	if (!fdf->img->addr)
		quit_app(fdf, 7);
	is_that_bob_ross(fdf);
	mlx_hook(fdf->img->mlx_win, 17, 0, (void *)quit_app, fdf);
	mlx_hook(fdf->img->mlx_win, 2, 1L << 0, key_events, fdf);
	mlx_mouse_hook(fdf->img->mlx_win, mouse_events, fdf);
	mlx_loop(fdf->img->mlx);
}

void	menu(t_img *img, t_opts *opts)
{
	char	*menu;
	float	x;
	float	y;

	y = opts->win_height * 0.05;
	x = opts->win_width * 0.85;
	menu = "[Arrows]            Move view";
	mlx_string_put(img->mlx, img->mlx_win, x, y += 20, 0xccccff, menu);
	menu = "[Wheel] [+] [-]     Zoom in, zoom out";
	mlx_string_put(img->mlx, img->mlx_win, x, y += 20, 0xccccff, menu);
	menu = "[1] [2]             Change altitude scaling";
	mlx_string_put(img->mlx, img->mlx_win, x, y += 20, 0xccccff, menu);
	menu = "[Q] [W]             Rotate";
	mlx_string_put(img->mlx, img->mlx_win, x, y += 20, 0xccccff, menu);
	menu = "[Tab] [Space]       Change projection angle";
	mlx_string_put(img->mlx, img->mlx_win, x, y += 20, 0xccccff, menu);
	menu = "[Esc]               Close";
	mlx_string_put(img->mlx, img->mlx_win, x, y += 20, 0xccccff, menu);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (!argv[0] || !argv[1] || (argc != 2))
		quit("Invalid arguments");
	fdf = calloc(1, sizeof(t_fdf));
	if (!fdf)
		quit("Memory allocation failed (fdf)");
	fdf->img = calloc_er(1, sizeof(t_img), fdf, 1);
	fdf->map = calloc_er(1, sizeof(t_map), fdf, 1);
	fdf->opts = calloc_er(1, sizeof(t_opts), fdf, 1);
	fdf->map->file = check_file(fdf, argv[1]);
	fdf->map->height = 0;
	fdf->map->width = __INT_MAX__;
	fdf->map->data = NULL;
	cartographer(fdf);
	if (fdf->map->height <= 1 || fdf->map->width <= 1
		|| !fdf->map->height || !fdf->map->width)
		quit_app(fdf, 2.5);
	init_opts(fdf);
	alloc_positions(fdf);
	positions(fdf);
	init_mlx(fdf);
	return (0);
}
