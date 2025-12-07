/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:03:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/07 09:38:13 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (!is_valid_input(argc, argv))
		return (1);
	// 1.INITIALIZE DATA
	fdf.map.height = 0;
	fdf.map.width = 0;
	fdf.map.grid = NULL;
	// 2.PARSE MAP
	get_map_dimensions(argv[1], &fdf.map);
	allocate_map(&fdf.map);
	fill_map(argv[1], &fdf.map);
	// 3.GRAPHICS
	init_graphics(&fdf);
	mlx_hook(fdf.win, 2, 1L << 0, handle_keypress, &fdf);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	// TEST DRAW
	int y = 200;
	while (y < 400)
	{
		int x = 300;
		while (x < 500)
		{
			my_pixel_put(&fdf, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_loop(fdf.mlx);
	return (0);
}
