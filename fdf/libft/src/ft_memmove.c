/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:50:18 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/29 20:39:58 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*aux_dest;
	unsigned char	*aux_src;

	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (aux_dest < aux_src)
	{
		while (n-- != 0)
			*aux_dest++ = *aux_src++;
	}
	else
	{
		aux_dest += n;
		aux_src += n;
		while (n-- != 0)
			*(--aux_dest) = *(--aux_src);
	}
	return (dest);
}
