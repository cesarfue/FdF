/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:40:04 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/02 16:28:49 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*calloc_er(t_fdf *fdf, size_t nmemb, size_t size)
{
	void	*ret;
	static int		i;

	
	ret = (i++ == 9 ? NULL : ft_calloc(nmemb, size));
	ft_printf("%d ", i);
	if (ret == NULL)
		quit_app(fdf, 1);
	return (ret);
}

void	err_code(int err)
{
	if (err == 1)
		quit("Memory allocation failed");
	else if (err == 2)
		quit("Error occured inside mlx functions");
}

void	quit_app(t_fdf *fdf, int err)
{
	if (fdf && fdf->img && fdf->img->mlx && fdf->img->img)
		mlx_destroy_image(fdf->img->mlx, fdf->img->img);
	if (fdf && fdf->img && fdf->img->mlx && fdf->img->mlx_win)
		mlx_destroy_window(fdf->img->mlx, fdf->img->mlx_win);
	if (fdf && fdf->img && fdf->img->mlx)
		mlx_destroy_display(fdf->img->mlx);
	if (fdf && fdf->map)
		freetab_ext((void **)fdf->map->data, fdf->map->height);
	if (fdf && fdf->pos && fdf->map)
		freetab_in((void **)fdf->pos, fdf->map->height);
	if (fdf && fdf->map)
		free(fdf->map);
	if (fdf && fdf->pos)
		free(fdf->pos);
	if (fdf && fdf->opts)
		free(fdf->opts);
	if (fdf && fdf->img)
	{
		free(fdf->img->mlx);
		free(fdf->img);
	}
	free(fdf);
	if (err != 0)
		err_code(err);
	else
		exit(0);
}
