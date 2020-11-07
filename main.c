#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open()

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	int 	fd;
	char	*line;

	line = (char *)malloc(1000);
	if ((fd = open("test1", O_RDWR)) != -1)
		while (get_next_line(fd, &line) == 1)
			printf("%s\n", line);
	close(fd);
	// while (1);
	return (0);
}
