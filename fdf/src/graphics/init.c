/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:38:47 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/06 18:36:41 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_graphics(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return ;
	fdf->win = mlx_new_window(fdf->mlx, 800, 600, "FdF - Wireframe");
	if (!fdf->win)
	{
		free(fdf->mlx);
		return ;
	}
	fdf->img = mlx_new_image(fdf->mlx, 800, 600);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_len, &fdf->endian);
}

/*
1. Initialize the library
    This establishes the connection to the X server (Linux) or Window system (Mac)
2. Create the Window
	Arguments: mlx_ptr, width, height, title

If the fdf->mlx fails, In the future, I should exit cleanly here
*/