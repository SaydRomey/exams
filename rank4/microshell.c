/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:03:12 by cdumais           #+#    #+#             */
/*   Updated: 2024/02/06 00:18:11 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define ERR_ARGC "error: cd: bad arguments\n"
#define ERR_CD "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal\n"
#define ERR_EXEC "error: cannot execute "

int err(const char *str)
{
	write(2, str, strlen(str));
	return (1);
}

int cd(char **argv)
{
	if (chdir(argv[1]) == -1)
	{
		err(ERR_CD);
		err(argv[1]);
		err("\n");
		return (1);
	}
	return (0);
}

// Improved exec_cmd function to handle pipes more accurately
int exec_cmd(char **argv, char **envp)
{
	int pipefd[2];
	int pid, status = 0;
	int need_pipe = 0;

	// Split commands at pipes and execute sequentially
	for (int i = 0; argv[i] != NULL; i++) {
		if (strcmp(argv[i], "|") == 0 || argv[i + 1] == NULL) {
			if (strcmp(argv[i], "|") == 0) {
				need_pipe = 1;
				argv[i] = NULL; // Terminate the current command sequence before the pipe
			}

			if (need_pipe && pipe(pipefd) == -1)
				return err(ERR_FATAL);

			pid = fork();
			if (pid == -1)
				return err(ERR_FATAL);

			if (pid == 0) { // Child process
				if (need_pipe) {
					dup2(pipefd[1], STDOUT_FILENO); // Redirect STDOUT to input of the next command
					close(pipefd[0]);
					close(pipefd[1]);
				}
				if (execve(argv[0], argv, envp) == -1) {
					err(ERR_EXEC);
					err(argv[0]);
					err("\n");
					exit(1); // Ensure exit to avoid continuing in the child process
				}
			} else { // Parent process
				if (need_pipe) {
					dup2(pipefd[0], STDIN_FILENO); // Redirect STDIN to output of the last command
					close(pipefd[0]);
					close(pipefd[1]);
				}
				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
					status = WEXITSTATUS(status);
				need_pipe = 0; // Reset for the next command sequence
				argv += i + 1; // Move to the next command after the pipe
				i = -1; // Reset index for the new shifted argv
			}
		}
	}
	return status;
}

int microshell(int argc, char **argv, char **envp)
{
	int i = 1; // Start from argv[1]

	while (i < argc) {
		int j = i;
		while (j < argc && strcmp(argv[j], ";") != 0) 
			j++;
		argv[j] = NULL; // Temporarily terminate the current segment

		if (j != i) { // Execute only if there's a command
			if (strcmp(argv[i], "cd") == 0) {
				if (j - i != 2) // 'cd' command and one argument
					err(ERR_ARGC);
				else
					cd(&argv[i]);
			} else {
				exec_cmd(&argv[i], envp);
			}
		}

		i = j + 1; // Move to the next command after ';'
	}
	return 0;
}

int main(int argc, char **argv, char **envp)
{
	if (argc > 1) {
		return microshell(argc, argv, envp);
	}
	return 0;
}
