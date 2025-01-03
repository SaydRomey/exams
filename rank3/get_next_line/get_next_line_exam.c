
/*
Assignment name : get_next_line
Expected files : get_next_line.c
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:

char *get_next_line(int fd);

Your function must return a line that has been read
	from the file descriptor passed as parameter.

What we call a "line that has been read"
is a succession of 0 to n characters
that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n'
in case there is one at the end of the line that has been read.
When you've reached the EOF, you must store the current buffer in a char *
and return it.

If the buffer is empty you must return NULL.
In case of error return NULL.
In case of not returning NULL, the pointer should be free-able.

Your program will be compiled with the flag -D BUFFER_SIZE=xx,
which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free.
When you've reached the EOF,
your function should keep 0 memory allocated with malloc,
except the line that has been returned.

Calling your function get_next_line() in a loop
will therefore allow you to read the text available on a file descriptor
one line at a time until the end of the text,
no matter the size of either the text or one of its lines.

Make sure that your function behaves well when
it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor
between 2 calls of get_next_line().

Finally we consider that get_next_line() has an undefined behaviour
when reading from a binary file.
*/

#include <unistd.h> 
#include <stdlib.h> 

/*
malloc a new string with 2 more spaces (the char 'c' and a '\0')
copy old string to the new string
then append the new char and the null terminator
free the old string, return the new string
*/
static char	*append_char(char *str, char c, int length)
{
	int		i;
	char	*new_str;

	new_str = malloc(length + 2);
	if (!new_str)
		return (free(str), NULL);
	i = 0;
	while (i < length)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[length] = c;
	new_str[length + 1] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1]; //to store characters read from the file
	static int	buffer_index = 0; //keep track of the current position in the buffer
	static int	buffer_size = 0; //store the number of characters read into the buffer
	char		*line = NULL;// Pointer to the line to be returned
	int			line_length = 0; //keep track of the length of the line

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(fd, buffer, BUFFER_SIZE); // Read from file into the buffer
			if (buffer_size <= 0)
				break; // EOF or read error
			buffer_index = 0; // Reset buffer index after reading new data
		}
		while (buffer_index < buffer_size)
		{
			line = append_char(line, buffer[buffer_index], line_length); // Append character from buffer to the line
			if (!line)
				return (NULL);
			if (buffer[buffer_index++] == '\n') //check for newline and increment index *(increments buffer_index if found or not)*
				return (line); //If newline character is found, return the current line
			line_length++; // Increment line length
		}
	}
	if (line_length == 0)
		return (free(line), NULL); // If no data was read, free line and return NULL
	return (line); // Return the line read from the file
}

/* -------------------------------------------------------------------------- */

// #include <stdio.h>
// #include <fcntl.h>

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	int		line_nbr = 1;

// 	if (argc != 2)
// 		return (printf("usage\n"), 1);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (printf("fd\n"), 1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("[l.%d] %s", line_nbr, line);
// 		free(line);
// 		line = get_next_line(fd);
// 		line_nbr++;
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
// // EOF (test)