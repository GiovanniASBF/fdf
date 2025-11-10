/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:50:01 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/26 10:46:28 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	aux = (char *)malloc((len + 1) * sizeof(char));
	if (aux == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		aux[i] = s[start + i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

/*
#include <stdio.h>
int	main (void)
{
	char const *str = "testando meu codigo";
	char *result = ft_substr(str, 20, 1);
	printf("Result: %s\n", result);
}
*/