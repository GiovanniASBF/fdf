/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:38:30 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/29 20:02:51 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	aux = (char *)malloc((len + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	while (i < len)
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

/*
When I call malloc, i define the size by "len + 1"
to assure space for the null terminator
*/