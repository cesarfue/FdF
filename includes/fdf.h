/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:10:13 by cesar             #+#    #+#             */
/*   Updated: 2024/01/15 15:25:34 by cefuente         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_view
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
}	t_view;

typedef struct s_map
{
	char	*file;
	int		**data;
	int		**iso;
	int		width;
	int		height;
}	t_map;


void	def_view(t_view *s_view, t_map *s_map);
void	cartographer(t_map *s_map);
void	draw(t_view s_view, t_map s_map);

#endif