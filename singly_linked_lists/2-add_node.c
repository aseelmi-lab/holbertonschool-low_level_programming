#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: double pointer to the list_t list.
 * @str: string to be added to the new node.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int length = 0;

	while (str[length])
		length++;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = length;
	new->next = *head;
	*head = new;

	return (new);
}
