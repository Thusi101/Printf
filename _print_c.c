#include "main.h"
#include <stdarg.h>

/**
 * print_c - creates characters
 * @val: Varaidic arguments
 * Return: counter
*/
int print_c(va_list val)
{
	char character;

	character = va_arg(val, int);
	return (_putchar(character));
}
