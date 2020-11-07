#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open()

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	int 	fd;
	char	*line;

	if (argc > 1)
	{
		if ((fd = open(argv[1], O_RDWR)) != -1)
			if (get_next_line(fd, &line) != -1)
				printf("%s\n", line);
		close(fd);
	}
	char *l;
	l = NULL;
	printf("%p\n", &l);
	return (0);
}
