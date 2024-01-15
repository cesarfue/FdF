/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/12 17:31:32 by cesar            ###   ########.fr       */
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
	cartographer(&s_map);
	def_view(&s_view, &s_map);
	draw(s_view, s_map);
	return (0);
}