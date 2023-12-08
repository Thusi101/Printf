#include "main.h"

/**
 *print_unsigned - Prints an unsigned number
@buff: Buffer array to handle print
@args: List of arguments
@warns: calculats active flags
@width: get width
@size: Size specifier
@precision: precision specification
Return: number of chars printed.
*/
int print_unsigned(va_list args, char buffer[],
int warns, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = convert_size_unsigned(num, size);
    if (num == 0)
        buff[i--] = '0';

    buff [BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buff[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return (write_unsigned(0, i, buff, warns,
    width, precision, size));
}

/**
 * print_oct - prints an unsigned number in octal notation
 * @buff: buffer array to handle print
 * @args: List of argurments
 * @warns: Calculate active flags
 * @width: get Width
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int print_oct(va_list val, char buff[], int warns, 
int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsigned(num, size);

    if (num == 0)
        buff[i--] = '0';

    buff[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buff[i--] = (num % 8) + '0';
        num /=8;
    }
    if (warns & W_HASH && init_num != 0)
        buff[i--] = '0';

    i++;

    return (write_unsigned(0, i, buff, warns, width, precision, size));
}

/**
 * print_hex - prints an unsigned number in hexadecimal notation
 * @buff: buff array to handle print
 * @val: Lists of arguments
 * @warns: Calculate active warns
 * @width: get width
 * @precision: precision spcification
 * @size: size specifier
 * return: number of chars printed
*/
int print_hex(va_list val, char buff[], int warns,
int width, int precision, int size);
{
    return (print_hex(types, "0123456789abcdef", buff, 
    warns, 'x', width, precision, size));
}

/**
 * print_hex_extra - Prints an unsigned number in upper hexadecimal notation
 * @args: Lists of arguments
 * @buff: buffer array to handle print
 * @warns: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
*/
int print_HEX_extra(va_list val, char map_to[], char buff[],
int warns, char warn_ch, int width, int precision, int size);
{
    return (print_HEX_extra(types, "0123456789ABCDEF", buff,
    warns, 'X', width, precision, size));
}

/**print_hex - prints a hexadeciaml number in lower or upper
 * @val: Lists of arguments
 * @map_to: array of values to map the number to
 * @buff: Buffer array to handle print
 * @warns: Calculates active flags
 * @warns_a: Calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of Chars printed 
*/
int print_hex(va_list val, char map_to[], char buff[],
int warns, char warns-a, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_args(val, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsigned(num, size);

    if (num == 0)
    buff[i--] = '0';

    buff[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buff[i--] = map_to[num % 16];
        num /= 16;
    }

    if (warns & W_HASH && init_num != 0)
    {
        buff[i--] = warns_a;

    }

    i++;

    return (write_unsigned(0, i, buff, warns, width, precision, size));
}