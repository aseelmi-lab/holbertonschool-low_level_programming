#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 * Return: A pointer to the table, or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * sorted_list_add - Inserts node into sorted list
 * @ht: Sorted hash table
 * @new: New node to insert
 */
void sorted_list_add(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
		return;
	}
	if (strcmp(new->key, ht->shead->key) < 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
		return;
	}
	tmp = ht->shead;
	while (tmp->snext != NULL && strcmp(new->key, tmp->snext->key) > 0)
		tmp = tmp->snext;
	new->sprev = tmp;
	new->snext = tmp->snext;
	if (tmp->snext == NULL)
		ht->stail = new;
	else
		tmp->snext->sprev = new;
	tmp->snext = new;
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: Sorted hash table
 * @key: The key
 * @value: The value
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->next;
	}
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;
	sorted_list_add(ht, new);
	return (1);
}

/**
 * shash_table_get - Retrieves value associated with a key
 * @ht: Sorted hash table
 * @key: Key to find
 * Return: The value, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints sorted hash table
 * @ht: Sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned char flag = 0;

	if (ht == NULL)
		return;
	printf("{");
	node = ht->shead;
	while (node)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints sorted hash table in reverse
 * @ht: Sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned char flag = 0;

	if (ht == NULL)
		return;
	printf("{");
	node = ht->stail;
	while (node)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: Sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;
	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}
	free(ht->array);
	free(ht);
}
