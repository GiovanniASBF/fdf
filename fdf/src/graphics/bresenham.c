/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:10:34 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/29 18:26:07 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int n);
static void	init_bresenham_params(t_point start, t_point end, t_bresenham *b);

void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	t_bresenham	b;
	int			e2;

	init_bresenham_params(start, end, &b);
	while (1)
	{
		my_pixel_put(fdf, start.x, start.y, 0xFFFFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * b.err;
		if (e2 > -b.dy)
		{
			b.err -= b.dy;
			start.x += b.sx;
		}
		if (e2 < b.dx)
		{
			b.err += b.dx;
			start.y += b.sy;
		}
	}
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	init_bresenham_params(t_point start, t_point end, t_bresenham *b)
{
	b->dx = ft_abs(end.x - start.x);
	b->dy = ft_abs(end.y - start.y);
	if (start.x < end.x)
		b->sx = 1;
	else
		b->sx = -1;
	if (start.y < end.y)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
}
