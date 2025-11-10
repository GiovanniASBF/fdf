/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:50:55 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/07/29 19:52:45 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_memory(int i, char **str);
static	int	count_words(char *str, char d);
static	char	*get_word(char *str, char delimiter);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		numb_of_str;
	char	**res;

	if (!s)
		return (NULL);
	numb_of_str = count_words((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (numb_of_str + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = get_word((char *)s, c);
			if (!res[i])
				return (free_memory(i, res), NULL);
			s += ft_strlen(res[i++]);
		}
	}
	res[i] = NULL;
	return (res);
}

static	void	free_memory(int i, char **str)
{
	while (i--)
		free(str[i]);
	free(str);
}

static	int	count_words(char *str, char d)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != d && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == d)
			in_word = 0;
		str++;
	}
	return (count);
}

static	char	*get_word(char *str, char delimiter)
{
	int		len;
	char	*letter;
	char	*start;
	char	*word;

	start = str;
	letter = str;
	while (*letter != delimiter && *letter)
		letter++;
	len = letter - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

/*
#include <stdio.h>
int	main(void)
{
	char *str = "C4i do cav4lo na m4nha de s4xta";
	char **res = ft_split(str, '4');
	int	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}
At line 39 i used a C feature called the comma operator.
It lets you evaluate multiple expressions, from left to right, 
and returns the value of the last one.
But it just works because free_memory() returns nothing (it's void).
It just runs free_memory() for its side effect, and return NULL.
*/