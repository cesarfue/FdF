/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/16 09:14:45 by cesar            ###   ########.fr       */
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
	fdf->opts->tile_width = fdf->map->dotX;
	fdf->opts->tile_height = fdf->map->dotY;
}



int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (!argv[0] || !argv[1] || (argc != 2))
		quit("Invalid arguments");
	fdf.map.file = argv[1];
	cartographer(&fdf);
	def_view(&fdf);
	draw(fdf);
	return (0);
}