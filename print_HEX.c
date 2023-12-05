#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
* print_exc_string - prints exclusive strings
* @val: the arguements
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
_putchar('\\');
_putchar('x')
length = length + 2;
value = s[i];
if (value < 16)
{
_putchar('0');
length++;
}
length += print_HEX_extra(value);
}
else
{
_putchar(string[i]);
length++;
}
return (length);
}
