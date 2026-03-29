#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* حساب طول النص */
	while (str[len] != '\0')
		len++;

	/* حجز مساحة (الطول + 1 للحرف الصفري) */
	dup = malloc(sizeof(char) * (len + 1));

	/* التحقق من نجاح malloc */
	if (dup == NULL)
		return (NULL);

	/* نسخ محتويات النص */
	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
}
