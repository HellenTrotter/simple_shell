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
	char *path = NULL;

	path = find_path(args[0]);
	child = fork();
	if (child == -1)
	{
		free(path);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)

	{
		exec_var = execve(path, args, envp);
		if (exec_var == -1)
		{
			free(path);
			perror(cmd);
			_exit(1);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(path);
	}

}
/*void err_message(char *name, char *cmd, char *arg)
{
	_strcpy(name, cmd);
	_strcat(name, ":");
	_strcat(name, " ");
	_strcat(name, "1");
	_strcat(name, " ");
	_strcat(name, arg);
	_strcat(name, ":");
	_strcat(name, " ");
	_strcat(name, "not found");
}*/
