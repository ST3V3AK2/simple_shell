#include "main.h"

/**
 * free_grid - frees a 2 dimentional array
 * @grid: 2 dimentional array
 * @height: height of the array
 * Return: void
 */

void free_grid(char **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		if (grid[i] != NULL)
			free(grid[i]);
	}
	free(grid);
}
