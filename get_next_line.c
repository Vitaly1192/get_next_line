#include "get_next_line.h"
#include <stdio.h>

/**
** 1 –– всё прочитано, записано и конец файла не был достигнут
** 0 –– линия прочитана, записана, но  файл закончился (была полседняя строчка)
** -1 –– в случаии любой ошибки, fd -–– испорчиный или не смогли аллоцировать память
**/

int	get_next_line(int fd, char ** line)
{
	static	char	*last_str;
	char			*array;
	char			*ptr_chr;
	int				f;
	int				r;

	if (fd < 0 || line == NULL)
		return (-1);
	array = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (array == NULL)
		return (-1);
	if (last_str != NULL)
	{
		if ((ptr_chr = ft_strchr(last_str, '\n')))
			{
				*ptr_chr = '\0';
				*line = ft_strdup(last_str);
				last_str = ft_strdup(ptr_chr + 1);
				return (1);
			}
			else
			{
				*line = ft_strdup(last_str);
				last_str = NULL;
			}
	}
	else
		*line = ft_strdup("");
	f = 1;
	while (f != 0 && (r = read(fd, array, BUFFER_SIZE)) != 0)
	{
		if (r == -1)
			return (-1);
		if (r == 0)
			return (0);
		array[r] = '\0';
		if ((ptr_chr = ft_strchr(array, '\n')) != NULL)
		{
			f = 0;
			*ptr_chr = '\0';
			free(last_str);
			last_str = ft_strdup(ptr_chr + 1);
			if (last_str == NULL)
				return (-1);
		}
		*line = ft_strjoin_to_endline_and_free(*line, array);
		if (*line == NULL)
		{
			free(array);
			return (-1);
		}
	}
	return (!f);
}
//leaks a.out
