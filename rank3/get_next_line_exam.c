
 #include <unistd.h> 
 #include <stdlib.h> 

 #ifndef BUFFER_SIZE 
 # define BUFFER_SIZE 42 
 #endif

// char *get_next_line(int fd) 
// { 
// 	int		i = 0; 
// 	int		rd = 0; 
// 	char	character; 
// 	char	*buffer = malloc(10000); 
  
// 	if (BUFFER_SIZE <= 0) 
// 		return (free(buffer), NULL); 
// 	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0) 
// 	{ 
// 		buffer[i++] = character; 
// 		if (character == '\n') 
// 			break; 
// 	} 
// 	if ((!buffer[i - 1] && !rd) || rd == -1) 
// 	{ 
// 		free(buffer); 
// 		return (NULL); 
// 	} 
// 	buffer[i] =  '\0'; 
// 	return(buffer); 
// }

// 

char	*get_next_line(int fd)
{
	int		index;
	int		bytes;
	char	*buffer;
	char	character;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	index = 0;
	bytes = read(fd, &character, 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (bytes > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, 1);
	}
	if ((bytes <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}

/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_nbr = 1;
	
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: could not open file %s\n", argv[1]);
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("[%d] %s\n", line_nbr, line);
		free(line);
		line = get_next_line(fd);
		line_nbr++;
	}
	free(line);
	close(fd);
	return (0);
}
// EOF