/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:03:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/06 17:26:43 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map	map;
	int		x;
	int		y;

	if (!is_valid_input(argc, argv))
		return (1);
	map.height = 0;
	map.width = 0;
	map.grid = NULL;
	// 1.Measure
	get_map_dimensions(argv[1], &map);
	// 2.Allocate
	allocate_map(&map);
	// 3.Fill
	fill_map(argv[1], &map);
	// --- TEST CASE ---
	printf("Map Dimensions: %dx%d\n", map.width, map.height);
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			printf("%3d", map.grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	free_map(&map);
	return (0);
}
