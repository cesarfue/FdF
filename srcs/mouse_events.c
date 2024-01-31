/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:26:14 by cefuente          #+#    #+#             */
/*   Updated: 2024/01/31 17:31:17 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_was_touched(int key, t_fdf *fdf)
{
	if (key == 5)
		return (fdf->opts->scale -= 0.05, 1);
	if (key == 4)
		return (fdf->opts->scale += 0.05, 1);
	return (0);
}

int	mouse_events(int key, int x, int y, t_fdf *fdf)
{
	if (mouse_was_touched(key, fdf) == 1)
		new_image(fdf);
	return (0);
}
