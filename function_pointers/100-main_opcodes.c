#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int bytes, i;
	char *addr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* الحصول على عنوان بداية دالة main */
	addr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		if (i == bytes - 1)
		{
			/* لآخر بايت: نطبعه بدون مسافة بعده */
			printf("%02hhx\n", addr[i]);
			break;
		}
		/* طباعة البايت كـ hex من حرفين صغيرين */
		printf("%02hhx ", addr[i]);
	}

	return (0);
}
