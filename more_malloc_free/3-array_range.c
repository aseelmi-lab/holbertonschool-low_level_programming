#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: minimum value (included)
 * @max: maximum value (included)
 *
 * Return: pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	/* شرط الفشل الأول: إذا كان min أكبر من max */
	if (min > max)
		return (NULL);

	/* حساب عدد العناصر المطلوبة */
	size = max - min + 1;

	/* حجز الذاكرة */
	array = malloc(sizeof(int) * size);

	if (array == NULL)
		return (NULL);

	/* تعبئة المصفوفة بالأرقام من min إلى max */
	for (i = 0; i < size; i++)
	{
		array[i] = min;
		min++;
	}

	return (array);
}
