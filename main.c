#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open()

int	main(void)
{
	// int 	fd;
	// int		j;
	char	*line;

	int fd1 = open("test1", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	
	get_next_line(fd1, &line);
	printf("|%s|\n", line);
	get_next_line(fd2, &line);
	printf("|%s|\n", line);
	get_next_line(fd1, &line);
	printf("|%s|\n", line);
	get_next_line(fd2, &line);
	printf("|%s|\n", line);
	get_next_line(fd1, &line);
	printf("|%s|\n", line);
	get_next_line(fd2, &line);
	printf("|%s|\n", line);
	get_next_line(fd1, &line);
	printf("|%s|\n", line);
	get_next_line(fd2, &line);
	printf("|%s|\n", line);
	/*
	printf("##################################################\n");

	fd = open("test_one_line_with_endl", O_RDONLY);
	while ((j = get_next_line(fd, &line)) >= 0)
	{
		printf("|%s|\n", line);
		free(line);
		if (j == 0)
			break;
	}
	close(fd);

	printf("##################################################\n");
	
	fd = open("test_empty_file", O_RDONLY);
	while ((j = get_next_line(fd, &line)) >= 0)
	{
		printf("|%s|\n", line);
		free(line);
		if (j == 0)
			break;
	}
	close(fd);

	printf("##################################################\n");

	fd = open("test_only_one_line", O_RDONLY);
	while ((j = get_next_line(fd, &line)) >= 0)
	{
		printf("|%s|\n", line);
		free(line);
		if (j == 0)
			break;
	}
	close(fd);

	printf("##################################################\n");

	fd = open("test_a_lot_of_empty_lines", O_RDONLY);
	while ((j = get_next_line(fd, &line)) >= 0)
	{
		free(line);
		if (j == 0)
			break;
	}
	close(fd);

	printf("##################################################\n");

	fd = open("test_big_file", O_RDONLY);
	while ((j = get_next_line(fd, &line)) >= 0)
	{
		free(line);
		printf("|%s|\n", line);
		if (j == 0)
			break;
	}
	close(fd);

	printf("##################################################\n");
	*/
	printf("=========\n");
	printf("===END===\n");
	printf("=========\n");
	// scanf("%d", &fd);
	return (0);
}
