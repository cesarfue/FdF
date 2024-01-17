/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/17 16:23:19 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	positions(&fdf);
	init_mlx(&fdf);
	return (0);
}