/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:06:25 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/06 18:16:50 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_fdf *fdf)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_map(&fdf->map);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		exit(0);
	}
	return (0);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	free_map(&fdf->map);
	free(fdf->mlx);
	exit(0);
}
