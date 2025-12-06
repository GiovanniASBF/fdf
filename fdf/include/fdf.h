/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:04:13 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/06 14:37:09 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "mlx.h"

typedef struct s_map
{
	int	height;
	int	width;
	int	**grid;
}				t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

void	allocate_map(t_map *map);
int		count_words(char *str);
void	get_map_dimensions(char *filename, t_map *map);
int		is_valid_input(int argc, char *argv[]);
int		is_valid_extension(char *arg);

#endif