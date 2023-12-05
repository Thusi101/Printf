#include "main.h"

/**
 * print_char - Prints a char
 * @types: List an arguemnts
 * @size: Size specifier
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @precision: Precision specification
 * @width: Width
 * Return: Number of chars printed
 */

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);

#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

typedef int (*print_function)(va_list, char[], int, int, int, int);

typedef struct {
    char specifier;
    print_function printer;
} printer_specifier;

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);

printer_specifier specifiers[] = {
    {'c', print_char},
    {'s', print_string},
    {'%', print_percent},
    {'i', print_int},
    {'d', print_int},
    {'b', print_binary},
    /* Add more specifiers as needed */
    {0, NULL}
};

int _printf(const char *format, ...)
{
    // Existing code...

    for (i = 0; format && format[i] != '\0'; i++)
    {
        // Existing code...

        else
        {
            // Existing code...

            for (printer_specifier *spec = specifiers; spec->specifier != 0; spec++)
            {
                if (format[i + 1] == spec->specifier)
                {
                    printed = spec->printer(list, buffer, flags, width, precision, size);
                    // Existing code...
                }
            }
        }
    }

    // Existing code...
}

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);
    return handle_write_char(c, buffer, flags, width, precision, size);
}

// Similar modifications for other print functions...

