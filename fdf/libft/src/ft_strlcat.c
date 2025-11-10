/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:22 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/24 16:19:54 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	j;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	i = dst_len;
	j = 0;
	src_len = ft_strlen(src);
	if (size > dst_len)
	{
		while (i < size - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	return (size + src_len);
}

/*
Se o size for 0,
retorna src_len
*/