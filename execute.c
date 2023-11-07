#include "shell.h"

/**
 * exec - creates a child process and executes commands
 * @args: array of strings
 * @envp: environment variable
 * @cmd: name of executable file
 *
 */
void exec(char **args, char **envp, char *cmd)
{
	pid_t child;
	int status, exec_var;

	child = fork();
	if (child == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (!args)
			exit(EXIT_FAILURE);
		exec_var = execve(args[0], args, envp);
		if (exec_var == -1)
		{
			perror(cmd);
			_exit(1);
		}
	}
	else
	{
		waitpid(child, &status, 0);
	}
}
