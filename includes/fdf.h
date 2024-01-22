/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:10:13 by cesar             #+#    #+#             */
/*   Updated: 2024/01/22 16:33:00 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <../mlx_linux/mlx.h>
# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include <fcntl.h>
# include <math.h> 

# include <stdio.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2560
# endif

# ifndef WIN_HEIGHT 
#  define WIN_HEIGHT 1600
# endif

# ifndef SCALE
#  define SCALE 0.8
# endif

# ifndef ALT_SCALE
#  define ALT_SCALE 5
# endif

# ifndef ANGLE 
#  define ANGLE 0.9
# endif

# ifndef VIEW_Y 
#  define VIEW_Y 100
# endif

# ifndef VIEW_X
#  define VIEW_X 500
# endif

typedef struct s_pos
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_pos;

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
	float	img_width;
	float	img_height;
	float	step;
	float	angle;
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	int		min_z;
	int		max_z;
	int		scale;
	int		alt_scale;
	int		view_x;
	int		view_y;
}	t_opts;

typedef struct s_fdf
{
	t_map	*map;
	t_opts	*opts;
	t_pos	**pos;
}	t_fdf;

void	define_view(t_fdf *fdf);
void	cartographer(t_fdf *fdf);
void	alloc_positions(t_fdf *fdf);
void	init_mlx(t_fdf *fdf);
float	absol(float i);
float	max(float x, float y);
void	calc_min_max(t_pos pos, t_opts *opts);
void	define_scale(t_fdf *fdf);
void	scale_positions(t_fdf *fdf);
void	define_view(t_fdf *fdf);
void	iso(t_pos *pos, float angle);
void	positions(t_fdf *fdf);
void	colors(t_opts *opts, t_pos *pos);
void	gradient(t_pos *pos, t_pos *npos, float i, float px);
int		key_events(int key, t_opts *opts);



#endif