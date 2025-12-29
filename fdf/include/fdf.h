/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:04:13 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/29 18:30:50 by gaguiar-         ###   ########.fr       */
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
}			t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
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
void	fill_map(char *filename, t_map *map);
void	free_map(t_map *map);
void	free_split(char	**arr);
int		get_fd(char *filename);
void	get_map_dimensions(char *filename, t_map *map);
int		handle_keypress(int keysym, t_fdf *fdf);
void	init_graphics(t_fdf *fdf);
int		is_valid_input(int argc, char *argv[]);
int		is_valid_extension(char *arg);
void	my_pixel_put(t_fdf *fdf, int x, int y, int color);

#endif