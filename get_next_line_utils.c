/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwinky <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:00:00 by dwinky            #+#    #+#             */
/*   Updated: 2020/11/12 22:01:17 by dwinky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
