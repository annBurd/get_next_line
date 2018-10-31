#include "get_next_line.h"
#include <stdio.h>
// # include <sys/types.h>
// # include <sys/stat.h>
// # include <string.h>
// # include <unistd.h>

int main(int argc, char const *argv[])
{
	int		fd;
	char	*line;

	if (argc == 1)
		printf("no file to open\n");
	else if (argc > 1)
	{
		int n = 1;
		while (n < argc)
		{
			fd = open(argv[n], O_RDONLY);
			while (get_next_line(fd, &line) > 0)
			{
				printf("%s\n", line);
				ft_strdel(&line);
			}
			close(fd);
			printf("=========================\n");
			n++;
		}
	}
	system("leaks gnl");
	return 0;
}