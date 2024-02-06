/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:03:12 by cdumais           #+#    #+#             */
/*   Updated: 2024/02/06 13:39:50 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://github.com/pasqualerossi/42-School-Exam-Rank-04
// https://github.com/Glagan/42-exam-rank-04/tree/master/microshell // (using dlinklist)

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define ERR_ARGC "error: cd: bad arguments\n"
#define ERR_CD "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal\n"
#define ERR_EXEC "error: cannot execute "

// bool
#define TRUE 1
#define FALSE 0

// strcmp
#define SAME 0

// return status
#define SUCCESS 0
#define FAILURE 1
#define ERROR -1

// std file descriptors
#define STDIN 0
#define STDOUT 1
#define STDERR 2

// pipe ends
#define READ_END 0
#define WRITE_END 1

int	ft_strlen(const char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_puterr(const char *str)
{
	write(STDERR, str, ft_strlen(str));
	return (FAILURE);
}

int	ft_puterr_arg(const char *str, const char *arg)
{
	write(STDERR, str, ft_strlen(str));
	write(STDERR, arg, ft_strlen(arg));
	return (ft_puterr("\n"));
}

int cd(char **argv)
{
	if (chdir(argv[1]) == ERROR)
		return (ft_puterr_arg(ERR_CD, argv[1]));
	return (SUCCESS);
}

int exec_cmd(char **argv, char **envp)
{
	int pipefd[2];
	int pid;
	int	status = SUCCESS;
	int need_pipe = FALSE;

	// Split commands at pipes and execute sequentially
	int	i = 0;
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i], "|") == SAME || argv[i + 1] == NULL)
		{
			if (strcmp(argv[i], "|") == SAME)
			{
				need_pipe = TRUE;
				argv[i] = NULL; // Terminate the current command sequence before the pipe
			}
			if (need_pipe == TRUE && pipe(pipefd) == ERROR)
				return (ft_puterr(ERR_FATAL));

			pid = fork();
			if (pid == ERROR)
				return (ft_puterr(ERR_FATAL));

			if (pid == 0) // Child process
			{
				if (need_pipe)
				{
					dup2(pipefd[WRITE_END], STDOUT); // Redirect STDOUT to input of the next command
					close(pipefd[READ_END]);
					close(pipefd[WRITE_END]);
				}
				if (execve(argv[0], argv, envp) == ERROR)
				{
					ft_puterr_arg(ERR_EXEC, argv[0]);
					exit(FAILURE); // exit to avoid continuing in the child process
				}
			}
			else // Parent process
			{
				if (need_pipe)
				{
					dup2(pipefd[READ_END], STDIN); // Redirect STDIN to output of the last command
					close(pipefd[READ_END]);
					close(pipefd[WRITE_END]);
				}
				waitpid(pid, &status, 0);
				if (WIFEXITED(status)) // Child process terminated normally
					status = WEXITSTATUS(status); // Get the exit status of the child process
				need_pipe = FALSE; // Reset for the next command sequence
				argv += i + 1; // Move to the next command after the pipe
				i = -1; // Reset index for the new shifted argv
			}
		}
		i++;
	}
	return (status);
}

int microshell(int argc, char **argv, char **envp)
{
	int i = 1; // Start from argv[1] (skip program name)
	int	j; // To get to the end of a command

	while (i < argc)
	{
		j = i;
		while (j < argc && strcmp(argv[j], ";") != SAME) 
			j++;
		argv[j] = NULL; // Temporarily terminate the current segment

		if (j != i) // Execute only if there's a command
		{
			if (strcmp(argv[i], "cd") == SAME)
			{
				if (j - i != 2) // 'cd' command and one argument
					ft_puterr(ERR_ARGC);
				else
					cd(&argv[i]);
			}
			else
				exec_cmd(&argv[i], envp);
		}
		i = j + 1; // Move to the next command after ';'
	}
	return (SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		return (microshell(argc, argv, envp));
	}
	return (0);
}

// ./a.out /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
