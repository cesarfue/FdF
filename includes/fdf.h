/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:10:13 by cesar             #+#    #+#             */
/*   Updated: 2023/12/17 12:51:14 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <../mlx_linux/mlx.h>
# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include <fcntl.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

# ifndef WIN_HEIGHT 
#  define WIN_HEIGHT 1080
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
	int		unit_width;
	int		unit_height;
}	t_view;

typedef struct s_map
{
	char	*file;
	int		**data;
	int		width;
	int		height;
}	t_map;

void	def_view(t_view *s_view, t_map *s_map);
void	cartographer(t_map *s_map);
void	draw(t_view s_view, t_map s_map);

#endif