/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:35:42 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/06 14:44:47 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		*ptr_count;

	count = 0;
	ptr_count = &count;
	va_start(args, format);
	ft_pntf_input_handler(args, format, ptr_count);
	va_end(args);
	return (count);
}
