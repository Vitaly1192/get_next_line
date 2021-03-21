/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwinky <dwinky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:00:00 by dwinky            #+#    #+#             */
/*   Updated: 2021/03/21 22:43:55 by dwinky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		*ft_calloc(size_t number, size_t size)
{
	unsigned char	*point;
	size_t			k;
	size_t			range;

	range = number * size;
	k = 0;
	point = (unsigned char *)malloc(range);
	if (point != NULL)
		while (k != range)
			*(point + k++) = '\0';
	return (point);
}

void		ft_clear_tail(char **s_tail)
{
	free(*s_tail);
	*s_tail = NULL;
}

char		*ft_strdup(const char *str)
{
	size_t	k;
	char	*dup;

	dup = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	k = 0;
	if (dup != NULL)
		while (str[k] != '\0')
		{
			dup[k] = str[k];
			k++;
		}
	return (dup);
}

size_t		ft_strlen(const char *str)
{
	char const *str_cpy;

	str_cpy = str;
	while (*str != '\0')
		str++;
	return (str - str_cpy);
}

char		*ft_strchr(char *str, int c)
{
	size_t	k;

	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] == c)
			return ((str + k));
		k++;
	}
	if (str[k] == c)
		return ((str + k));
	return (NULL);
}
