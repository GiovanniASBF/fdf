/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:03:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2026/01/03 19:30:34 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_camera(t_fdf *fdf);
static void	init_hooks(t_fdf *fdf);
static void	init_map_struct(t_map *map);

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (!is_valid_input(argc, argv))
		return (1);
	init_map_struct(&fdf.map);
	get_map_dimensions(argv[1], &fdf.map);
	allocate_map(&fdf.map);
	fill_map(argv[1], &fdf.map);
	init_graphics(&fdf);
	init_camera(&fdf);
	init_hooks(&fdf);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_loop(fdf.mlx);
	return (0);
}

static void	init_camera(t_fdf *fdf)
{
	fdf->zoom = (800 / fdf->map.width);
	if (fdf->zoom < 2)
		fdf->zoom = 2;
	if (fdf->zoom > 40)
		fdf->zoom = 40;
	fdf->offset_x = 400;
	fdf->offset_y = 300 - (fdf->map.height * fdf->zoom) / 4;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
}

static void	init_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, key_handle, fdf);
	mlx_hook(fdf->win, 4, 1L << 2, mouse_handle, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}

static void	init_map_struct(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->grid = NULL;
}
