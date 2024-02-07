/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:40:04 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/07 13:28:06 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*calloc_er(size_t nmemb, size_t size, t_fdf *fdf, float err)
{
	void		*ret;

	ret = ft_calloc(nmemb, size);
	if (ret == NULL)
		quit_app(fdf, err);
	return (ret);
}

void	err_code(float err)
{
	if (err == 0)
		exit(0);
	else if (err == 1)
		quit("Memory allocation failed (1; fdf structures)");
	else if (err == 1.5)
		quit("Invalid file or extension (program must be called with a .fdf)");
	else if (err == 2)
		quit("Memory allocation failed (2; parsing)");
	else if (err == 2.5)
		quit("Invalid map (width and height must be greater than 1)");
	else if (err == 3)
		quit("Memory allocation failed (3; positions)");
	else if (err >= 4)
		quit("Error occured inside mlx functions (4 - 6)");
}

void	quit_app(t_fdf *fdf, float err)
{
	if (err >= 6 || err == 0)
	{
		mlx_destroy_image(fdf->img->mlx, fdf->img->img);
		mlx_destroy_window(fdf->img->mlx, fdf->img->mlx_win);
		mlx_destroy_display(fdf->img->mlx);
	}
	if (err >= 4 || err == 0)
		free(fdf->img->mlx);
	if (err >= 3 || err == 0)
		freetab_in((void **)fdf->pos, fdf->map->allocs);
	if (err >= 2 || err == 0)
		freetab((void **)fdf->map->data, fdf->map->height);
	if (err >= 1 || err == 0)
	{
		free(fdf->pos);
		free(fdf->img);
		free(fdf->opts);
		free(fdf->map);
		free(fdf);
	}
	err_code(err);
}
