#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to concatenate from src
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* 1. الوصول إلى نهاية النص dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* 2. إضافة n بايت من src إلى نهاية dest */
	/* يتوقف إذا وصل لـ n أو وجد علامة نهاية النص '\0' في src */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* 3. إغلاق النص الناتج بالعلامة الصفرية */
	dest[i] = '\0';

	return (dest);
}
