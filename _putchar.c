#include "main.h"
/**
 * _putchar - this is the putchar function
 *@c: input entry
 * Return: 1 &c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
