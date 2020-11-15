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

/*
** 1 –– всё прочитано, записано и конец файла не был достигнут
** 0 –– линия прочитана, записана, но  файл закончился (была последняя строчка)
** -1 –– при любой ошибки: fd –– испорчиный, не смогли аллоцировать память и тд.
*/

int		ft_clear(char **str, char *str2)
{
	free(*str);
	*str = NULL;
	free(str2);
	return (-1);
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
	ft_clear(s1, NULL);
	return (str - k);
}

int		check_tail(char **line, char **s_tail, char **find_end, char **array)
{
	char	*cur_ptr;

	cur_ptr = NULL;
	if ((*s_tail) != NULL && (*find_end = ft_strchr(*s_tail, '\n')))
	{
		*(*find_end) = '\0';
		if (!(*line = ft_strdup(*s_tail)))
			return (ft_clear(s_tail, NULL));
		cur_ptr = *s_tail;
		if (!(*s_tail = ft_strdup(*find_end + 1)) && ft_clear(&cur_ptr, NULL))
			return (-1);
		ft_clear(&cur_ptr, NULL);
		return (1);
	}
	else if (*s_tail != NULL)
	{
		if ((*line = ft_strdup(*s_tail)) == NULL)
			return (ft_clear(s_tail, NULL));
		ft_clear(s_tail, NULL);
	}
	else
		*line = (char *)ft_calloc(1, 1);
	if (*line == NULL || !(*array = (char *)malloc(BUFFER_SIZE + 1)))
		return (ft_clear(s_tail, NULL));
	return (2);
}

int		set_line(char **array, char **s_tail, char **find_end)
{
	if ((*find_end = ft_strchr(*array, '\n')) != NULL)
	{
		*(*find_end) = '\0';
		free(*s_tail);
		if (!(*s_tail = ft_strdup(*find_end + 1)))
			return (ft_clear(s_tail, *array));
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	char	*s_tail = NULL;
	char			*array;
	char			*find_end;
	int				r;

	find_end = NULL;
	if (fd < 0 || line == NULL || read(fd, find_end, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if ((r = check_tail(line, &s_tail, &find_end, &array)) == -1)
		return (-1);
	else if (r == 1)
		return (1);
	while (!find_end && (r = read(fd, array, BUFFER_SIZE)) > 0)
	{
		array[r] = '\0';
		if (set_line(&array, &s_tail, &find_end) == -1)
			return (-1);
		if ((*line = ft_strjoin_to_endline_and_free(line, array)) == NULL)
			return (ft_clear(&s_tail, array));
	}
	if (r < 0)
		return (ft_clear(&s_tail, array));
	free(array);
	return (r == 0 ? 0 : 1);
}
