#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	long n = 612852475143;
	long d = 2;

	while (d * d <= n)
	{
		if (n % d == 0)
		{
			n /= d;
		}
		else
		{
			d++;
		}
	}
	printf("%ld\n", n);
	return (0);
}
