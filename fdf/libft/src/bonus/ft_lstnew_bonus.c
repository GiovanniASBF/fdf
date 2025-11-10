/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:33:55 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/30 12:20:38 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*obj1;

	obj1 = (t_list *)malloc(sizeof(*obj1));
	if (!obj1)
		return (NULL);
	obj1->content = content;
	obj1->next = NULL;
	return (obj1);
}
