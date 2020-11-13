#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open()

int	main(void)
{
	int 	fd;
	int		j;
	char	*line;

	fd = open("test1", O_RDONLY);
	while ((j = get_next_line(2, &line)) >= 0)
	{
		printf("|%s|\n", line);
		free(line);
		if (j == 0)
			break;
	}
	close(fd);
	// while (--j > 0)
	// 	free(lineadress[j - 1]);
	printf("END\n");
	// while (1);
	return (0);
}
