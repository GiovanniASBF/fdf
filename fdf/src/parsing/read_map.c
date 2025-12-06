/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:35:17 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/06 13:19:33 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_fd(char *filename);

void	get_map_dimensions(char *filename, t_map *map)
{
	int		current_width;
	int		fd;
	char	*line;

	fd = get_fd(filename);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		current_width = count_words(line);
		if (map->width == 0)
			map->width = current_width;
		else
		{
			if (map->width != current_width)
			{
				ft_printf("Error: Invalid map.\n");
				exit(EXIT_FAILURE);
			}
		}
		map->height++;
		free(line);
	}
	close(fd);
}

static int	get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open the file '%s' (%s)\n",
			filename, strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}
