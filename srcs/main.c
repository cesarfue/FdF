/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:31 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/15 19:31:40 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	s_map;

	if (!argv[0] | !argv[1] | argc != 2)
		quit("Invalid arguments"); 
	s_map.file = argv[1];
	parsing(s_map); 
	draw(s_map);
	return (0);
}