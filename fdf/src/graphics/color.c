/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:42:10 by gaguiar-          #+#    #+#             */
/*   Updated: 2026/01/03 16:49:29 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z, t_map *map)
{
	(void) map;
	if (z > 10)
		return (WHITE);
	if (z > 0)
		return (RED);
	if (z == 0)
		return (GREEN);
	return (BLUE);
}
