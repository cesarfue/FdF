/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:10:13 by cesar             #+#    #+#             */
/*   Updated: 2024/01/17 14:16:11 by cefuente         ###   ########.fr       */
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

# ifndef ALT_SCALE
#  define ALT_SCALE 0.5
# endif

typedef s_dot
{
	int	x;
	int	y;
	int	z;
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
	int		tile_width;
	int		tile_height;
	int		alt_scale;
}	t_opts;

typedef struct s_fdf
{
	s_img	img;
	s_map	map;
	s_dot	**dot;
	s_opts	opts;
}	t_fdf;

void	def_view(t_fdf *fdf);
void	cartographer(t_fdf *fdf);
void	init_mlx(t_fdf fdf);

#endif