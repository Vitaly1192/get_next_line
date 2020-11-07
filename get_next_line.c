#include "get_next_line.h"
// #include <stdio.h>
// #define BUFFER_SIZE 

// 1 –– всё прочитано, записано и конец файла не был достигнут
// 0 –– линия прочитана, записана, но  файл закончился (была полседняя строчка)
// -1 –– в случаии любой ошибки, fd -–– испорчиный или не смогли аллоцировать память

int	get_next_line(int fd, char **line)
{
	(void) fd;
	(void) line;
	char	*mas;
	int		k;
	int		f;

	if (fd < 0 || line == NULL)
		return (-1);
	f = 1;
	mas = (char *)malloc(BUFFER_SIZE + 1);
	if (mas == NULL)
		return (-1);
	while ((read(fd, mas, BUFFER_SIZE) != 0) && f != 0)
	{
		k = 0;
		while (mas[k] != '\n' && k < BUFFER_SIZE)
			k++;
		if (mas[k] != '\n')
		{
			f = -1; // конец строки не найден, возвращаем -1
			continue ;
		}
		else
		{
			f = 0;
			*line = (char *)malloc(k + 1);
			if (*line == NULL)
				return (-1);
			k = 0;
			while (k != BUFFER_SIZE && mas[k] != '\n')
			{
				line[0][k] = mas[k];
				k++;
			}
			(*line)[BUFFER_SIZE] = '\0';
			f = 1;
		}
	}
	free(mas);
	return (f);
}
