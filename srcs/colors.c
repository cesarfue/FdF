/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:45:48 by cesar             #+#    #+#             */
/*   Updated: 2024/01/31 15:12:48 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	colors(t_opts *opts, t_pos *pos)
{
	if (pos->z == opts->min_z)
		pos->color = 0x1F2544;
	else if (pos->z >= opts->min_z && pos->z < opts->min_z + opts->sector)
		pos->color = 0x474F7A;
	else if (pos->z >= opts->min_z + opts->sector
		&& pos->z < opts->min_z + opts->sector * 2)
		pos->color = 0x81689D;
	else if (pos->z >= opts->min_z + opts->sector * 2)
		pos->color = 0xFFD0EC;
}

int	gr_red(int start_red, int end_red, float ratio)
{
	int	start;
	int	end;

	start = (start_red >> 16) & 0xFF;
	end = (end_red >> 16) & 0xFF;
	return (start + ratio * (end - start));
}

int	gr_green(int start_green, int end_green, float ratio)
{
	int	start;
	int	end;

	start = (start_green >> 8) & 0xFF;
	end = (end_green >> 8) & 0xFF;
	return (start + ratio * (end - start));
}

int	gr_blue(int start_blue, int end_blue, float ratio)
{
	int	start;
	int	end;

	start = start_blue & 0xFF;
	end = end_blue & 0xFF;
	return (start + ratio * (end - start));
}

void	gradient(t_pos *pos, t_pos *npos, float i, float px)
{
	float	ratio;
	int		red;
	int		green;
	int		blue;

	ratio = i / px;
	red = gr_red(pos->color, npos->color, ratio);
	green = gr_green(pos->color, npos->color, ratio);
	blue = gr_blue(pos->color, npos->color, ratio);
	pos->color = (red << 16) | (green << 8) | blue;
}
