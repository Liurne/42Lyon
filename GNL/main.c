#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd;
	int i;
	char	*line;

	i = 1;
	fd = open("fileTest/bible.txt", O_RDONLY);
	if(fd == -1)
	{
		printf ("fail\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s line %d\n",line, i);
	while(line)
	{
		i++;
		line = get_next_line(fd);
		printf("%s line %d\n", line,i);
	}
	free(line);
	close (fd);
	return (0);
}