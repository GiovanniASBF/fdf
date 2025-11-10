/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_converter_pntf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:01:40 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/06 14:44:10 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_pntf_hexlen(unsigned long ptr);
void			ft_pntf_printhex(unsigned long ptr, char *base, int *count);

void	ft_pntf_printptr(void *ptr, int *count)
{
	if (!ptr)
		ft_pntf_print_str("(nil)", count);
	else
	{
		ft_pntf_print_str("0x", count);
		ft_pntf_printhex((unsigned long)ptr, "0123456789abcdef", count);
	}
}

void	ft_pntf_printhex(unsigned long ptr, char *base, int *count)
{
	char	*hex;
	size_t	i;
	size_t	len;

	if (ptr == 0)
		ft_pntf_print_char('0', count);
	else
	{
		len = ft_pntf_hexlen(ptr);
		hex = ft_calloc((len + 1), sizeof(char));
		if (!hex)
			return ;
		i = len - 1;
		while (ptr != 0)
		{
			hex[i--] = base[ptr % 16];
			ptr = ptr / 16;
		}
		ft_pntf_print_str(hex, count);
		free(hex);
	}
}

static size_t	ft_pntf_hexlen(unsigned long ptr)
{
	size_t	i;

	i = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

void	ft_pntf_printnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_pntf_print_str("-2147483648", count);
		return ;
	}
	else if (n < 0)
	{
		ft_pntf_print_char('-', count);
		ft_pntf_printnbr(-n, count);
	}
	else
	{
		if (n > 9)
			ft_pntf_printnbr(n / 10, count);
		ft_pntf_print_char((n % 10) + '0', count);
	}
}

void	ft_pntf_printunbr(unsigned int n, int *count)
{
	if (n > 9)
		ft_pntf_printunbr(n / 10, count);
	ft_pntf_print_char((n % 10) + '0', count);
}
