#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, f1_head, f1_tail, f2_head, f2_tail;
	unsigned long next_head, next_tail, limit = 1000000000;
	int count;

	printf("%lu, %lu", f1, f2);
	for (count = 3; count <= 92; count++)
	{
		f2 = f1 + f2;
		f1 = f2 - f1;
		printf(", %lu", f2);
	}
	f1_head = f1 / limit;
	f1_tail = f1 % limit;
	f2_head = f2 / limit;
	f2_tail = f2 % limit;
	for (count = 93; count <= 98; count++)
	{
		next_tail = f1_tail + f2_tail;
		next_head = f1_head + f2_head + (next_tail / limit);
		next_tail %= limit;
		printf(", %lu%09lu", next_head, next_tail);
		f1_head = f2_head;
		f1_tail = f2_tail;
		f2_head = next_head;
		f2_tail = next_tail;
	}
	printf("\n");
	return (0);
}
