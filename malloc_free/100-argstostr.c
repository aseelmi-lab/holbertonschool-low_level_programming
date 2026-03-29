#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program.
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* 1. حساب الطول الإجمالي */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* مساحة للـ \n بعد كل كلمة */
	}
	len++; /* مساحة للـ \0 في نهاية النص بالكامل */

	/* 2. حجز المساحة */
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	/* 3. نسخ النصوص وإضافة \n */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';

	return (str);
}
