/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:03:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/10 15:15:41 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error: Wrong number of arguments.\n");
		ft_printf("Usage: ./fdf <map_file.fdf>\n");
		return (1);
	}
	if (!is_valid_extension(argv[1]))
	{
		ft_printf("Error: Invalid argument.\n");
		return (1);
	}
	return (0);
}
