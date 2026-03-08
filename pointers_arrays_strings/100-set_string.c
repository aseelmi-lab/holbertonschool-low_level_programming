#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to the pointer we want to set
 * @to: string (pointer) to set it to
 *
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
