#include "shell.h"

/**
 * main_exec_file - executes command
 * @args: array of strings
 * @envp: environment variables
 * @cmd: name of executable
 * @input: pointer to user input
 *
 * Return: function to be executed
 */
int main_exec_file(char **args, char **envp, char *cmd, char *input)
{
	char *builtin_cmd[] = {"exit", "env"};
	command_function builtin_function[] = {&exit_shell, &print_environment};
	int i;

	if (args[0] == NULL)
		return (-1);
	i = 0;
	while (i < 2)
	{
		if (_strcmp(args[0], builtin_cmd[i]) == 0)
			return ((*builtin_function[i])(args, input));
		i++;
	}

	return (exec(args, envp, cmd));
}

/**
 * exec - creates a child process and executes commands
 * @args: array of strings
 * @envp: environment variable
 * @cmd: name of executable file
 *
 * Return: 0 on success, -1 on failure
 */
int exec(char **args, char **envp, char *cmd)
{
	pid_t child;
	int status, exec_var;
	char *path = NULL;
	char *error_message = NULL;

	/* finds the path of the command if the coomand is not a bin executable*/
	path = find_path(args[0]);
	if (path == NULL)
	{
		error_message = err_message(args, cmd);
		if (error_message == NULL)
			return (-1);
		free(error_message);
		return (-1);
	}
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

	return (0);
}

/**
 * err_message - prints the a customized error message if command is not found
 * @args: array of strings containing the commands entered by user
 * @cmd: name of program
 *
 * Return: pointer to the error message
 */
char *err_message(char **args, char *cmd)
{
	char *error_message = NULL;
	ssize_t w;

	error_message = malloc(sizeof(char) * 100);
	if (error_message == NULL)
		return (NULL);
	full_message(error_message, args[0], cmd);
	w = write(STDERR_FILENO, error_message, _strlen(error_message));
	if (w == -1)
	{
		perror("Error ");
		free(error_message);
		return (NULL);
	}

	return (error_message);
}

/**
 * full_message - used to customize the error message printed when command
 * is not found
 * @message: ponter to allocated space for the error message
 * @cmd: name of the command that could not be found
 * @arg: name of the program
 *
 */
void full_message(char *message, char *cmd, char *arg)
{
	char *ptr = ": ";

	_strcpy(message, arg);
	_strcat(message, ptr);
	_strcat(message, "1");
	_strcat(message, ptr);
	_strcat(message, cmd);
	_strcat(message, ptr);
	_strcat(message, "not found\n");
}
