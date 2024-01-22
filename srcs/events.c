/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:58 by cesar             #+#    #+#             */
/*   Updated: 2024/01/22 16:32:32 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_tap(int key)
{
	return (key == 126 || key == 125 || key == 123 || key == 124);
}

void	hooker(int key, t_opts *opts)
{
	if (key == 126)
		opts->view_x -= 40;
	if (key == 125)
		 opts->view_x += 40;
	if (key == 123)
		opts->view_y -= 40;
	if (key == 124)
		opts->view_y += 40;
}

int	key_events(int key, t_opts *opts)
{
	if (key_tap(key))
		hooker(key, opts);
	return (0);
}



