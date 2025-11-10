/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:24:20 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/26 10:50:37 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	len_s1_s2;
	char	*result;

	len_s1_s2 = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(((len_s1_s2 + 1) * sizeof(char)));
	if (result == NULL)
		return (NULL);
	aux = result;
	while (*s1)
	{
		*aux = *s1;
		aux++;
		s1++;
	}
	while (*s2)
	{
		*aux = *s2;
		aux++;
		s2++;
	}
	*aux = '\0';
	return (result);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*res = ft_strjoin("", "42");
	printf("Resultado: %s\n", res);
}
*/