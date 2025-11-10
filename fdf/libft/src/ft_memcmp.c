/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:23:07 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/29 19:51:12 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *v2, size_t n)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_v2;
	size_t			i;

	aux_s1 = (unsigned char *)s1;
	aux_v2 = (unsigned char *)v2;
	i = 0;
	while (i < n)
	{
		if (aux_s1[i] != aux_v2[i])
			return (aux_s1[i] - aux_v2[i]);
		i++;
	}
	return (0);
}
