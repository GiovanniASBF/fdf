/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:03:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/19 10:04:55 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	int	fd;
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello, World!");
	mlx_loop(mlx);
	if (!is_valid_input(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open the file '%s' (%s)\n",
			argv[1], strerror(errno));
		return (1);
	}
	return (0);
}
