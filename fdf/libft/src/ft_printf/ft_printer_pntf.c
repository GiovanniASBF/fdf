/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_pntf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:58:48 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/06 14:44:41 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pntf_print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_pntf_print_str(char *str, int *count)
{
	if (str == NULL)
	{
		ft_pntf_print_str("(null)", count);
		return ;
	}
	while (*str)
	{
		ft_pntf_print_char(*str, count);
		str++;
	}
}
