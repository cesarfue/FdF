/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:10:13 by cesar             #+#    #+#             */
/*   Updated: 2023/12/15 20:34:11 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <../mlx_linux/mlx.h>
# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include <../libft/includes/get_next_line.h>
# include <fcntl.h>

#define WINSIZE_Y 1080
#define WINSIZE_X 1920
#define IMGSIZE_Y (WINSIZE_Y * 0.9)
#define IMGSIZE_X (WINSIZE_X * 0.9)
#define MARGIN (WINSIZE_Y * 0.2)

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_map
{
	char	*file;
	char	**content;
	int		xlen;
	int		ylen;
} t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	alt;
} t_point; 

t_map	parsing(t_map s_map);

#endif