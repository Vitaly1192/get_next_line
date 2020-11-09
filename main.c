#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open()

int	main(void)
{
	int 	fd;
	char	*line;
	int		ret;


	line = (char *)malloc(1000);
	fd = open("test1", O_RDONLY);
	
	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	ret = get_next_line(fd, &line);
	printf("%s| ret = (%d)\n", line, ret);

	// get_next_line(fd, &line);
	// printf("%s\n", line);

	printf("%d\n", get_next_line(fd, &line));
	
	printf("%d\n", get_next_line(fd, &line));

	printf("%d\n", get_next_line(fd, &line));

	printf("END\n");
	return (0);
}
