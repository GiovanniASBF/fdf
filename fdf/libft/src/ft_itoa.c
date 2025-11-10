/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:59:31 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/28 17:55:19 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*converter(int n, int len, int negative, char	*str);
static	int	numsize(int n);

char	*ft_itoa(int n)
{
	int		is_negative;
	int		len;
	char	*str;

	is_negative = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		len = 1;
	else
	{
		if (n < 0)
		{
			is_negative = 1;
			n = -n;
			len = 1;
		}
		len = len + numsize(n);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = converter(n, len, is_negative, str);
	return (str);
}

static	int	numsize(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*converter(int n, int len, int negative, char	*str)
{
	int	i;

	i = len - 1;
	str[len] = '\0';
	if (negative == 1)
		str[0] = '-';
	if (n == 0 && len == 1)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

/*
#include <stdio.h>
int main(void)
{
	char	*res = ft_itoa(-1);
	printf("res: %s\n", res);
}
*/