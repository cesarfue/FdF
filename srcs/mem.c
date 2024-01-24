/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:03:48 by cesar             #+#    #+#             */
/*   Updated: 2024/01/23 13:41:18 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void alloc_positions(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->pos = malloc(fdf->map->height * sizeof(t_pos *));
	if (!fdf->pos)
		quit("alloc faild -> pos");
	while (i <= fdf->map->height)
	{
		fdf->pos[i] = malloc(fdf->map->width * sizeof(t_pos));
		if (!fdf->pos[i])
			quit("alloc faild -> pos");
		i++;
	}
}

void free_tab(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i <= fdf->map->height)
		free(fdf->pos[i++]);
	free(fdf->pos);
}