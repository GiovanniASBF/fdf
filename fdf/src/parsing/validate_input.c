/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:30:30 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/10 15:22:17 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_extension(char *arg)
{
	size_t	len;
	char	*ext;
	size_t	ext_start;

	len = ft_strlen(arg);
	if (len < 5)
		return (0);
	ext = ".fdf";
	ext_start = len - 4;
	arg += ext_start;
	if (!ft_strncmp(arg, ext, 4))
		return (1);
	else
		return (0);
}
