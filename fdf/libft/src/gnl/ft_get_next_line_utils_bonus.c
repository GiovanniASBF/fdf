/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:49:48 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/06 14:51:51 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd_buffer	*ft_gnl_find_node(t_fd_buffer *head, int fd)
{
	t_fd_buffer	*current;

	current = head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_gnl_delete_node(t_fd_buffer **head, int fd)
{
	t_fd_buffer	*temp;
	t_fd_buffer	*current;

	current = *head;
	if (current && (current->fd == fd))
	{
		*head = current->next;
		free(current->buffer);
		free(current);
		return ;
	}
	while (current && (current->next))
	{
		if (current->next->fd == fd)
		{
			temp = current->next;
			current->next = temp->next;
			free(temp->buffer);
			free(temp);
			return ;
		}
		current = current->next;
	}
}

t_fd_buffer	*ft_gnl_node_builder(t_fd_buffer *node,	t_fd_buffer	*head, int fd)
{
	node = (t_fd_buffer *)malloc(sizeof(t_fd_buffer));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->buffer = ft_strdup("");
	node->next = head;
	return (node);
}

char	*ft_gnl_update_buffer(char *buffer, char *line)
{
	char	*temp;
	size_t	line_len;

	line_len = ft_strlen(line);
	temp = buffer;
	buffer = ft_substr(temp, line_len, (ft_strlen(temp) - line_len));
	free(temp);
	return (buffer);
}
