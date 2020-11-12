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
** 0 –– линия прочитана, записана, но  файл закончился (была полседняя строчка)
** -1 –– при любой ошибки: fd –– испорчиный, не смогли аллоцировать память и тд.
*/

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
	static	char	*s_last_str = NULL;
	char			*array;
	char			*ptr_chr;
	int				f;
	int				r;

	if (fd < 0 || line == NULL)
		return (-1);
	if (s_last_str != NULL)
	{
		if ((ptr_chr = ft_strchr(s_last_str, '\n')))
			{
				*ptr_chr = '\0';
				*line = ft_strdup(s_last_str);
				if (*line == NULL)
				{
					free(s_last_str);
					return (-1);
				}
				free(s_last_str);
				s_last_str = ft_strdup(ptr_chr + 1);
				if (s_last_str == NULL)
					return (-1);
				return (1);
			}
			else
			{
				*line = ft_strdup(s_last_str);
				free(s_last_str);
				s_last_str = NULL;
			}
	}
	else
		*line = (char *)ft_calloc(1, 1);
	if (*line == NULL)
	{
		free(s_last_str);
		s_last_str = NULL;
		return (-1);
	}
	array = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (array == NULL)
	{
		free(s_last_str);
		s_last_str = NULL;
		return (-1);
	}
	f = 1;
	while (f != 0 && (r = read(fd, array, BUFFER_SIZE)) != 0)
	{
		if (r == -1)
		{
			free(array);
			free(s_last_str);
			array = NULL;
			s_last_str = NULL;
			return (-1);
		}
		array[r] = '\0';
		if ((ptr_chr = ft_strchr(array, '\n')) != NULL)
		{
			f = 0;
			*ptr_chr = '\0';
			free(s_last_str);
			s_last_str = ft_strdup(ptr_chr + 1);
			if (s_last_str == NULL)
			{
				free(array);
				free(s_last_str);
				array = NULL;
				s_last_str = NULL;
				return (-1);
			}
		}
		*line = ft_strjoin_to_endline_and_free(line, array);
		if (*line == NULL)
		{
			free(array);
			free(s_last_str);
			array = NULL;
			s_last_str = NULL;
			return (-1);
		}
	}
	if (r == 0)
	{
			free(*line);
			*line = ft_strdup("");
			free(array);
			free(s_last_str);
			array = NULL;
			s_last_str = NULL;
			return (0);
	}
	free(array);
	// printf("*line 		|%p\n", *line);
	// printf("array 		|%p\n", array);
	// printf("s_last_str	|%p\n", s_last_str);
	// free(array);
	return (!f);
}

/* leaks a.out */
