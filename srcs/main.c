/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/16 20:48:10 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_view	s_view;
	t_map	s_map;

	if (!argv[0] | !argv[1] | (argc != 2))
		quit("Invalid arguments");
	s_map.file = argv[1];
	def_view(&s_view);
	cartographer(&s_map);
	// draw(s_view, s_map);
	ft_printf("height is %d  || width is %d\n", s_map.height, s_map.width);
	for (int y = 0; y < s_map.height; y++)
	{
		for (int x = 0; x < s_map.width; x++)
			ft_printf("%d ", s_map.content[y][x]);
		ft_printf("\n");
	}
	return (0);
}