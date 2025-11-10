/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:32:02 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/24 16:36:46 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*aux;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	total_size = nmemb * size;
	if (total_size / nmemb != size)
	{
		return (NULL);
	}
	aux = malloc(total_size);
	if (aux == NULL)
	{
		return (NULL);
	}
	ft_memset(aux, 0, total_size);
	return (aux);
}

/*
The idea of return malloc(0) is to return a valid pointer. 
That make the usage of free() possible.
*/