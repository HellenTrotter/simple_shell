#include "shell.h"

/**
 * _getline - reads line from stream
 * @lineptr: buffer that sores lines read
 * @n: size of the buffer
 * @fd: stream to be read from
 *
 * Return: number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t bytes_read, total_read = 0;
	size_t i = 0, size = *n, new_size;
	char *buf = *lineptr, c;

	size = *lineptr == NULL ? (*n = BUFSIZE, BUFSIZE) : *n;
	buf = *lineptr == NULL ? malloc(sizeof(char) * BUFSIZE) : *lineptr;
	if (!buf)
		return (-1);
	do {
		bytes_read = read(fd, &c, 1);/*read single character*/
		if (bytes_read == -1)
		{
			free(buf);
			return (-1);
		}
		total_read += 1;/*increment totalread*/
		if (i + 1 > size)
		{
			new_size = size * 2;
			buf = _realloc(buf, size, new_size);
			if (!buf)
			{
				free(buf);
				return (-1);
			}
			size = new_size;
		}
		buf[i++] = c;
		if (c == '\n')
			break;
	} while (bytes_read > 0);
	if (total_read == 0)
	{
		free(buf);
		return (-1);
	}
	buf[i] = '\0';
	*lineptr = buf;
	*n = size;
	return (total_read);
}
