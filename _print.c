#include "main.h"
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024

/**
* print_buffer - Prints the contents of the buffer if it exists
* @buffer: Array of chars
* @buff_ind: Index at which to add the next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
}

/**
* _printf - The art of printing formatted output
* @format: The format string
* Return: The number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
char buffer[BUFF_SIZE];

if (!format)
return (-1);

va_start(list, format);

for (int i = 0; format[i]; ++i)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

