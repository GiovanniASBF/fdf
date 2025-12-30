/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:51:05 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/30 18:06:37 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	project_point(int x, int y, t_fdf *fdf);

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				bresenham(fdf, project_point(x, y, fdf),
					project_point(x + 1, y, fdf));
			if (y < fdf->map.height - 1)
				bresenham(fdf, project_point(x, y, fdf),
					project_point(x, y + 1, fdf));
			x++;
		}
		y++;
	}
}

static t_point	project_point(int x, int y, t_fdf *fdf)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = fdf->map.grid[y][x];
	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= fdf->zoom;
	project(&p, fdf);
	p.x += fdf->offset_x;
	p.y += fdf->offset_y;
	return (p);
}
