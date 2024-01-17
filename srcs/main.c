/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/17 15:00:22 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	def_view(t_fdf *fdf)
{
	fdf->opts->win_width = WIN_WIDTH;
	fdf->opts->win_height = WIN_HEIGHT;
	fdf->opts->img_width = fdf->opts->win_width * 0.8;
	fdf->opts->img_height = fdf->opts->win_height * 0.8;
	fdf->opts->margin_x = fdf->opts->win_width * 0.1;
	fdf->opts->margin_y = fdf->opts->win_height * 0.1;
	fdf->opts->dotX = fdf->opts->img_width / fdf->map->width;
	fdf->opts->dotY = fdf->opts->img_height / fdf->map->height;
}



int	main(int argc, char **argv)
{
	t_fdf	fdf;
	
	if (!argv[0] || !argv[1] || (argc != 2))
		quit("Invalid arguments");
	// fdf.img = malloc(sizeof(t_img));
	fdf.map = malloc(sizeof(t_map));
	fdf.opts = malloc(sizeof(t_opts));
	fdf.map->file = argv[1];
	cartographer(&fdf);
	def_view(&fdf);
	init_mlx(&fdf);
	return (0);
}