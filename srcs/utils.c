/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:35 by cesar             #+#    #+#             */
/*   Updated: 2024/01/31 09:46:31 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	absol(float i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

float	max(float x, float y)
{
	if (x >= y)
		return (x);
	return (y);
}

void	alloc_positions(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->pos = malloc((fdf->map->height) * sizeof(t_pos *));
	if (!fdf->pos)
		quit("alloc faild -> pos");
	while (i < fdf->map->height)
	{
		fdf->pos[i] = malloc((fdf->map->width) * sizeof(t_pos));
		if (!fdf->pos[i])
			quit("alloc faild -> pos");
		i++;
	}
}

void	free_tab(void **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}