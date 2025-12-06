/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:42:16 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/12/06 16:32:55 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
The Workflow:

    Open the file.

    Loop (y from 0 to height):

        Get the line (get_next_line).

        Split the line into tokens (char **nums = ft_split(line, ' ');).

        Inner Loop (x from 0 to width):

            Convert string to int: map->grid[y][x] = ft_atoi(nums[x]);

            (Optional: Handle color here later).

        Clean up: free_split(nums) and free(line).

    Close the file.
*/
static void	fill_line(t_map *map, char *line, int y);

void	fill_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = get_fd(filename);
	y = 0;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		fill_line(map, line, y);
		free(line);
		y++;
	}
	close(fd);
}

static void	fill_line(t_map *map, char *line, int y)
{
	char	**nums;
	int		x;

	nums = ft_split(line, ' ');
	if (!nums)
		return ;
	x = 0;
	while (nums[x])
	{
		map->grid[y][x] = ft_atoi(nums[x]);
		x++;
	}
	free_split(nums);
}
