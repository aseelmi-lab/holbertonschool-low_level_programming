#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to new space with s1 + s2, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	/* 1. التعامل مع الـ NULL كنصوص فارغة */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* 2. حساب أطوال النصوص */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* 3. حجز مساحة تكفي النصين + الحرف الصفري */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
		return (NULL);

	/* 4. نسخ النص الأول */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* 5. نسخ النص الثاني مباشرة بعد الأول */
	for (j = 0; j < len2; j++, i++)
		concat[i] = s2[j];

	/* 6. إضافة الحرف الصفري في النهاية */
	concat[i] = '\0';

	return (concat);
}
