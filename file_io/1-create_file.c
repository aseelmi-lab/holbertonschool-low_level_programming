#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: the string whose length to check.
 *
 * Return: integer length of string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;

	return (i);
}

/**
 * create_file - creates a file with specific permissions and content.
 * @filename: name of the file to create.
 * @text_content: NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_wrote;
	int len = 0;

	if (filename == NULL)
		return (-1);

	/* فتح الملف مع خيارات: إنشاء، كتابة فقط، وتفريغ إذا وجد */
	/* الصلاحيات 0600 تعني rw------- */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = _strlen(text_content);
		n_wrote = write(fd, text_content, len);
		if (n_wrote == -1 || n_wrote != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
