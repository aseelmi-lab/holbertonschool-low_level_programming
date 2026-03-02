#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to the result or 0 if buffer is small
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, l = 0, f, s, d = 0;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	if (i >= size_r || j >= size_r)
		return (0);
	i--, j--, size_r--;
	while (i >= 0 || j >= 0 || d)
	{
		f = (i >= 0) ? (n1[i--] - '0') : 0;
		s = (j >= 0) ? (n2[j--] - '0') : 0;
		if (l >= size_r)
			return (0);
		r[l++] = ((f + s + d) % 10) + '0';
		d = (f + s + d) / 10;
	}
	r[l] = '\0';
	for (k = 0, l--; k < l; k++, l--)
	{
		f = r[k];
		r[k] = r[l];
		r[l] = f;
	}
	return (r);
}
