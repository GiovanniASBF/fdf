/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:04:13 by gaguiar-          #+#    #+#             */
/*   Updated: 2026/01/03 16:46:31 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "keys.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>

# ifndef M_PI
#  define M_PI	3.14159265358979323846
# endif

# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

typedef struct s_map
{
	int	height;
	int	width;
	int	**grid;
}		t_map;

typedef struct s_fdf
{
	t_map	map;
	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		zoom;
	int		offset_x;
	int		offset_y;
}			t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_bresenham;

void	allocate_map(t_map *map);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
int		close_window(t_fdf *fdf);
int		count_words(char *str);
void	draw_map(t_fdf *fdf);
void	fill_map(char *filename, t_map *map);
void	free_map(t_map *map);
void	free_split(char	**arr);
int		get_color(int z, t_map *map);
int		get_fd(char *filename);
void	get_map_dimensions(char *filename, t_map *map);
int		handle_keypress(int keysym, t_fdf *fdf);
void	init_graphics(t_fdf *fdf);
int		is_valid_input(int argc, char *argv[]);
int		is_valid_extension(char *arg);
int		key_handle(int keycode, t_fdf *fdf);
int		mouse_handle(int button, int x, int y, t_fdf *fdf);
void	my_pixel_put(t_fdf *fdf, int x, int y, int color);
void	project(t_point *p, t_fdf *fdf);

#endif