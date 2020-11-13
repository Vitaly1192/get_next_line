/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwinky <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:59:43 by dwinky            #+#    #+#             */
/*   Updated: 2020/11/12 21:59:46 by dwinky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** 1 –– всё прочитано, записано и конец файла не был достигнут
** 0 –– линия прочитана, записана, но  файл закончился (была последняя строчка)
** -1 –– при любой ошибки: fd –– испорчиный, не смогли аллоцировать память и тд.
*/

void	free_and_set_null(char **str)
{
	free(*str);
	*str = NULL;
}

char	*ft_strjoin_to_endline_and_free(char **s1, char *s2)
{
	char	*str;
	size_t	k;

	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(*s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
	{
		free(*s1);
		return (NULL);
	}
	k = 0;
	while ((*s1)[k] != '\0')
	{
		*str++ = (*s1)[k];
		k++;
	}
	while (*s2 != '\0' && *s2 != '\n')
	{
		*str++ = *s2++;
		k++;
	}
	free(*s1);
	return (str - k);
}

int		get_next_line(int fd, char **line)
{
	static	char	*s_tail = NULL;
	char			*array;
	char			*find_end;
	int				r;

	if (fd < 0 || line == NULL)
		return (-1);
	if (s_tail != NULL && (find_end = ft_strchr(s_tail, '\n')))
	{
		*find_end = '\0';
		*line = ft_strdup(s_tail);
		if (*line == NULL)
		{
			free(s_tail);
			return (-1);
		}
		// free(s_tail); // надо это очистить, но после strdup()
		s_tail = ft_strdup(find_end + 1);
		if (s_tail == NULL)
			return (-1);
		return (1);
	}
	else if (s_tail != NULL)
	{
		*line = ft_strdup(s_tail);
		free_and_set_null(&s_tail);
	}
	else
		*line = (char *)ft_calloc(1, 1);
	if (*line == NULL)
	{
		free_and_set_null(&s_tail);
		return (-1);
	}
	if ((array = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
	{
		free_and_set_null(&s_tail);
		return (-1);
	}
	find_end = NULL;
	while (!find_end && (r = read(fd, array, BUFFER_SIZE)) != 0)
	{
		if (r == -1)
		{
			free(array);
			free_and_set_null(&s_tail);
			return (-1);
		}
		array[r] = '\0';
		if ((find_end = ft_strchr(array, '\n')) != NULL)
		{
			*find_end = '\0';
			free(s_tail);
			s_tail = ft_strdup(find_end + 1);
			if (s_tail == NULL)
			{
				free(array);
				free_and_set_null(&s_tail);
				return (-1);
			}
		}
		if ((*line = ft_strjoin_to_endline_and_free(line, array)) == NULL)
		{
			free(array);
			free_and_set_null(&s_tail);
			return (-1);
		}
	}
	free(array);
	return (find_end == NULL ? 0 : 1);
}
