/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:35 by cesar             #+#    #+#             */
/*   Updated: 2024/02/07 13:27:51 by cefuente         ###   ########.fr       */
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
	fdf->map->allocs = 0;
	fdf->pos = calloc_er(fdf->map->height, sizeof(t_pos *), fdf, 3);
	while (i < fdf->map->height)
	{
		fdf->pos[i] = calloc_er(fdf->map->width, sizeof(t_pos), fdf, 3);
		fdf->map->allocs++;
		i++;
	}
}

char	*check_file(t_fdf *fdf, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (ft_strnstr(&str[i - 4], ".fdf", 4) != NULL)
		return (str);
	quit_app(fdf, 0.5);
	return (NULL);
}
