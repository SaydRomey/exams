
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <sys/select.h>

// Declare the variables

int		count = 0, max_fd = 0;
int		ids[65536];
char	*msgs[65536];
fd_set	read_set, write_set, current;
char	buf_read[1001], buf_write[42];

// Copy extract_message from main

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

// Copy str_join from main

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

// Add error output function
void	fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void	send_to_all(int author, char *msg)
{
	int	fd = 0;
	while (fd <= max_fd)
	{
		if (FD_ISSET(fd, &write_set) && fd != author)
			send(fd, msg, strlen(msg), 0);
		fd++;
	}
}

void	register_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &current);
	sprintf(buf_write, "server: client %d just arrived\n", ids[fd]);
	send_to_all(fd, buf_write);
}

void	remove_client(int fd)
{
	sprintf(buf_write, "server: client %d just left\n", ids[fd]);
	send_to_all(fd, buf_write);
	free(msgs[fd]);
	msgs[fd] = NULL; //
	FD_CLR(fd, &current);
	close(fd);
}

void	send_msg(int fd)
{
	char	*msg;

	while (extract_message(&(msgs[fd]), &msg))
	{
		sprintf(buf_write, "client %d: ", ids[fd]);
		send_to_all(fd, buf_write);
		send_to_all(fd, msg);
		free(msg);
	}
}

int main(int argc, char **argv)
{
	// Handle arg error
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	FD_ZERO(&current); // add reset last client

	// Get this part from main and incorporate fatal_error()
	int	sockfd, connfd;
	socklen_t	len; // change int to socklen_t
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		fatal_error();
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr));

	max_fd = sockfd; // add
	FD_SET(max_fd, &current); // add

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); // replace 8081 by argv
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal_error();
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0)
		fatal_error();

	// implement loop
	while (1)
	{
		read_set = write_set = current;
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) < 0)
			fatal_error();

		int	fd = 0;
		while (fd <= max_fd)
		{
			if (!FD_ISSET(fd, &read_set))
			{
				fd++;
				continue; // no new message or clients, go to next fd
			}
			if (fd == sockfd) // new client detected
			{
				// get this part from main
				len = sizeof(cli);
				connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (connfd < 0)
					fatal_error();
				else
				{
					printf("server acccept the client...\n");
					register_client(connfd); // add the register_client function
				}
			}
			// add this part
			else // client quits (-1 recieved) or client sent a message
			{
				int	read_bytes = recv(fd, buf_read, 1000, 0);
				if (read_bytes <= 0)
				{
					remove_client(fd);
					break ;
				}
				buf_read[read_bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], buf_read);
				send_msg(fd);
			}
			fd++;
		}
	}
	return (0);
}
