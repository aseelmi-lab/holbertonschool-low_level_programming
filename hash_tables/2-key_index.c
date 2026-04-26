#include "hash_tables.h"

/**
 * key_index - gives you the index of a key.
 * @key: the key.
 * @size: the size of the array of the hash table.
 *
 * Return: the index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	/* 1. حساب الـ hash value باستخدام دالة djb2 */
	hash = hash_djb2(key);

	/* 2. تحويل الرقم الكبير إلى اندكس مناسب لحجم المصفوفة */
	return (hash % size);
}
