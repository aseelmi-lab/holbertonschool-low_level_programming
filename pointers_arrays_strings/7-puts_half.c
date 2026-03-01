#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: input string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i, n, len;

	len = 0;

	/* حساب طول النص */
	while (str[len] != '\0')
	{
		len++;
	}

	/* تحديد نقطة البداية للنصف الثاني */
	if (len % 2 == 0)
	{
		n = len / 2;
	}
	else
	{
		n = (len + 1) / 2;
	}

	/* طباعة النصف الثاني */
	for (i = n; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
