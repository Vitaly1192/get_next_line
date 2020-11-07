#include "get_next_line.h"
#include <stdio.h>
// #define BUFFER_SIZE 

// 1 –– всё прочитано, записано и конец файла не был достигнут
// 0 –– линия прочитана, записана, но  файл закончился (была полседняя строчка)
// -1 –– в случаии любой ошибки, fd -–– испорчиный или не смогли аллоцировать память

size_t		ft_strlen(const char *str)
{
	char const *str_cpy;

	str_cpy = str;
	while (*str != '\0')
		str++;
	return (str - str_cpy);
}

char	*ft_strjoin_to_newline(char const *s1, char const *s2)
{
	char	*str;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	k = 0;
	while (*s1 != '\0')
	{
		*str++ = *s1++;
		k++;
	}
	while (*s2 != '\0' && *s2 != '\n')
	{
		*str++ = *s2++;
		k++;
	}
	return (str - k);
}

int	get_next_line(int fd, char **line)
{
	char	*array;
	int		f;
	int		r;
	int		k;
	char	*cur_str;

 // read(fd, array, 0) == -1
	if (fd < 0 || line == NULL)
		return (-1);
	f = 1;
	array = (char *)malloc(BUFFER_SIZE + 1);
	if (array == NULL)
		return (-1);
	array[BUFFER_SIZE] = '\0';
	while ((r = read(fd, array, BUFFER_SIZE)) != 0)
	{
		if (r == 0)
			return (0);
		array[r] = '\0';
		k = 0;
		cur_str = *line;
		*line = ft_strjoin_to_newline(*line, array);
		free(cur_str);
		if (*line == NULL)
		{
			free(array);
			return (-1);
		}
		while (k != r)
		{
			if (array[k] == '\n')
				return (1);
			k++;
		}
		
		// k = 0;
		// while (array[k] != '\n' && k < BUFFER_SIZE)
		// 	k++;
		// if (array[k] != '\n')
		// {
		// 	f = -1; // конец строки не найден, возвращаем -1
		// 	continue ;
		// }
		// else
		// {
		// 	f = 0;
		// 	*line = (char *)malloc(k + 1);
		// 	if (*line == NULL)
		// 		return (-1);
		// 	k = 0;
		// 	while (k != BUFFER_SIZE && array[k] != '\n')
		// 	{
		// 		line[0][k] = array[k];
		// 		k++;
		// 	}
		// 	(*line)[BUFFER_SIZE] = '\0';
		// 	f = 1;
		// }
	}
	return (f);
}
//leaks a.out
