/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:10:13 by cesar             #+#    #+#             */
/*   Updated: 2024/01/17 18:13:06 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <../mlx_linux/mlx.h>
# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include <fcntl.h>
# include <math.h> 

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2560
# endif

# ifndef WIN_HEIGHT 
#  define WIN_HEIGHT 1600
# endif

# ifndef SCALE
#  define SCALE 0.5
# endif

typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
}	t_dot;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		**data;
	int		width;
	int		height;
	char	*file;
}	t_map;

typedef struct s_opts
{
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		margin_x;
	int		margin_y;
	int		dotX;
	int		dotY;
	int		scale;
	int		angle;
}	t_opts;

typedef struct s_fdf
{
	t_map	*map;
	t_opts	*opts;
	t_dot	**dot;
	t_dot	**pos;
}	t_fdf;

void	cartographer(t_fdf *fdf);
void	positions(t_fdf *fdf);
void	init_mlx(t_fdf *fdf);

#endif