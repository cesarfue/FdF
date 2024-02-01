/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:35 by cesar             #+#    #+#             */
/*   Updated: 2024/02/01 18:12:54 by cesar            ###   ########.fr       */
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
	fdf->pos = malloc_er((fdf->map->height) * sizeof(t_pos *));
	while (i < fdf->map->height)
	{
		fdf->pos[i] = malloc_er((fdf->map->width) * sizeof(t_pos));
		i++;
	}
}

void	freetab_in(void **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
}

void	freetab_in_out(void **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}