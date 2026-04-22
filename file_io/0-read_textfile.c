#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: pointer to the name of the file.
 * @letters: number of letters it should read and print.
 *
 * Return: actual number of letters it could read and print, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_wrote;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	n_read = read(fd, buf, letters);
	n_wrote = write(STDOUT_FILENO, buf, n_read);

	if (n_read == -1 || n_wrote == -1 || n_wrote != n_read)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (n_wrote);
}
