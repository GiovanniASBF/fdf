/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:06:01 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/31 16:28:52 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*node;

	node = *lst;
	if (!lst || !*lst || !del)
		return ;
	while (node)
	{
		next_node = node->next;
		del(node->content);
		free(node);
		node = next_node;
	}
	*lst = NULL;
}

/*
Once I free(node), the memory occupied by that node is deallocated, 
and I lose access to it. So, I'd lose the reference to the next node in the list.
Before freeing the node, I store the next node so I can safely continue iterating
*/