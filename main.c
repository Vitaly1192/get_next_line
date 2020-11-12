#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open()

int	main(void)
{
	int 	fd;
	int		j = 1;
	char	*line;
	char			*lineadress[13];

	//line = (char *)malloc(10);
	fd = open("test1", O_RDONLY);
	int i = 1;
	while (get_next_line(fd, &line) && i--)
	{
		// printf("%p\n", line);
		printf("|%s|\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	close(fd);
	free(line);
	while (--j > 0)
		free(lineadress[j - 1]);
	printf("END\n");
	while (1);
	return (0);
}
