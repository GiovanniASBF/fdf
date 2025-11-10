/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:38:05 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/29 19:46:48 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	unch_c;

	unch_c = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == unch_c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (unch_c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

/*
Cast to (unsigned char) to deal with large numbers input,
because the representation of large numbers can't fit in 
a signed char type (char).
*/