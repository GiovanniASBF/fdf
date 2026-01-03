/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:39:36 by gaguiar-          #+#    #+#             */
/*   Updated: 2026/01/03 17:57:19 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	deg_to_rad(double degrees);
static void		rotate_x(int *y, int *z, double alpha);
static void		rotate_y(int *x, int *z, double beta);
static void		rotate_z(int *x, int *y, double gama);

void	project(t_point *p, t_fdf *fdf)
{
	int		temp_x;
	int		temp_y;
	double	angle;

	(void)fdf;
	rotate_x(&p->y, &p->z, fdf->angle_x);
	rotate_y(&p->x, &p->z, fdf->angle_y);
	rotate_z(&p->x, &p->y, fdf->angle_z);
	angle = deg_to_rad(30);
	temp_x = p->x;
	temp_y = p->y;
	p->x = (temp_x - temp_y) * cos(angle);
	p->y = (temp_x + temp_y) * sin(angle) - p->z;
}

static double	deg_to_rad(double degrees)
{
	return (degrees * M_PI / 180.0);
}

static void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) - *z * sin(alpha);
	*z = previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = previous_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gama)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gama) - previous_y * sin(gama);
	*y = previous_x * sin(gama) + previous_y * cos(gama);
}
