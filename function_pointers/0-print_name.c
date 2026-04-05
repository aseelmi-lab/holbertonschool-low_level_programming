#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - prints a name
 * @name: name of the person
 * @f: pointer to the printing function
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
