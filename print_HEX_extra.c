#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
* print_exc_string - prints exclusive strings
* @val: a va_list arguement
* Return: integers
*/

int print_exc_string(va_list val)
{
	char *string;
	int i, length = 0;
	int value;
	
	string = va_arg(val, char *);
	if (string == NULL)
		string = "(null)";

	for (i = 0; string[i] != '\0'; i++)
{
	if (value < 16)
	_putchar('\\');
	_putchar('x')
	length += print_HEX_extra(value);
	if (value < 16)
	{
		_putchar('0');
		length++;
	}
}
else
{
_putchar(string[i]);
length++;
}
return (length);
}
int print_HEX_extra(char value)

return (0);
