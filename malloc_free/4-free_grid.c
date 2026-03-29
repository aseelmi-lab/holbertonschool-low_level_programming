#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid
 * @grid: 2D grid to free
 * @height: height of the grid
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	/* التأكد من أن المصفوفة ليست فارغة أصلاً */
	if (grid == NULL || height <= 0)
		return;

	/* 1. تحرير كل صف منفرداً */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	/* 2. تحرير المصفوفة الرئيسية التي تحتوي على مؤشرات الصفوف */
	free(grid);
}
