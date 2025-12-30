/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:39:36 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/30 17:41:06 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	deg_to_rad(double degrees);

void	project(t_point *p, t_fdf *fdf)
{
	int		temp_x;
	int		temp_y;
	double	angle;

	(void)fdf;
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
