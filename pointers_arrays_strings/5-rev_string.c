#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int len = 0;
	int i;
	char temp;

	/* حساب طول النص */
	while (s[len] != '\0')
	{
		len++;
	}

	/* تبديل الحروف من الأطراف وصولاً للمنتصف */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
