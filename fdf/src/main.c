/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:03:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/29 18:29:54 by gaguiar-         ###   ########.fr       */
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
	t_point start;
	t_point end;
	start.x = 100;
	start.y = 100;
	end.x = 700;
	end.y = 500;
	bresenham(&fdf, start, end);
	start.x = 100;
	start.y = 500;
	end.x = 700;
	end.y = 100;
	bresenham(&fdf, start, end);

	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_loop(fdf.mlx);
	return (0);
}
