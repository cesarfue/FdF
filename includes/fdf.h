/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:10:13 by cesar             #+#    #+#             */
/*   Updated: 2024/02/01 17:37:17 by cesar            ###   ########.fr       */
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
#  define WIN_WIDTH 1980
# endif

# ifndef WIN_HEIGHT 
#  define WIN_HEIGHT 1080
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
	void	*mlx;
	void	*mlx_win;
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
	float	step;
	float	angle;
	float	min_z;
	float	max_z;
	float	sector;
	float	range;
	float	scale;
	int		alt_scale;
	float	view_x;
	float	view_y;
	int		loops;
	float	rotate;
}	t_opts;

typedef struct s_fdf
{
	t_map	*map;
	t_opts	*opts;
	t_pos	**pos;
	t_img	*img;
}	t_fdf;

void	init_opts(t_fdf *fdf);
void	cartographer(t_fdf *fdf);
void	alloc_positions(t_fdf *fdf);
void	init_mlx(t_fdf *fdf);
float	absol(float i);
float	max(float x, float y);
void	calc_zmin_zmax(t_pos pos, t_opts *opts);
void	iso(t_pos *pos, t_opts *opts);
void	positions(t_fdf *fdf);
void	colors(t_opts *opts, t_pos *pos);
void	gradient(t_pos *pos, t_pos *npos, float i, float px);
int		key_events(int key, t_fdf *fdf);
void	is_that_bob_ross(t_fdf *fdf);
void	menu(t_img *img, t_opts *opts);
void	close_window(t_fdf *fdf);
int		mouse_events(int key, int x, int y, t_fdf *fdf);
void	new_image(t_fdf *fdf);
void	freetab_in(void **tab, int size);
void	freetab_in_out(void **tab, int size);

#endif