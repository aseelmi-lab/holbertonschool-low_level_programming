#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
	int len = 0;
	int o;

	while (*(s + len) != '\0')
	{
		len++;
	}

	for (o = len - 1; o >= 0; o--)
	{
		_putchar(*(s + o));
	}
	_putchar('\n');
}
