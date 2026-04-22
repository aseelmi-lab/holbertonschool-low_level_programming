#include "main.h"
#include <stdio.h>

/**
 * error_98 - handles read error
 * @filename: name of file
 */
void error_98(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * error_99 - handles write error
 * @filename: name of file
 */
void error_99(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * main - copies the content of a file to another file.
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, n_read, n_wrote;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_98(av[1]);
	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		error_99(av[2]);
	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_wrote = write(fd_to, buffer, n_read);
		if (n_wrote == -1 || n_wrote != n_read)
			error_99(av[2]);
	}
	if (n_read == -1)
		error_98(av[1]);
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}
