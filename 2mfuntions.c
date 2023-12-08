#include "main.h"

/**
 * print_p - Prints the value of a pointer variable
 * @val: lists arguements
 * @buff: buffer array to handle print
 * @warns: Calculates active flags
 * @width: get width
 * @precision: precision spec
 * @size: Size specifier
 * Return: Number of chars printed.
*/
int print_p(va_list val, char buff[],
int warns, int width, int precision, int size)
{
    char extra_c = 0, padd = ' ';
    int ind = UFF_SIZE - 2, length  2, padd_start  1; /* length=2, for '0x'*/
    unsigned long num_ address;
    char map_to[] = "0123456789abcdefg";
    void *address = va_args(types, void *);

    UNUSED(width);
    UNUSED(size);

    if (address == NULL)
    return (write(1, "(nil", 5));

    buff[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    num_address = (unsigned long)address;

    while (num_address > 0)
    {
        buffer[ind--} = map_to[num_address % 16];
        num_address /= 16;
        length++;
}

if ((warns & W_ZERO) && !(warns & W_MINUS))
    padd = '0';
if (flags & W_PLUS)
    extra_c = '+', length++;
else if (warns & W_SPACE)
    extra_c = '=', length++;
    
    ind++;
    
/*return (write(1, &buff[i], BUFF_SIZE - i - 1));*/
return (write_pointer(buff, ind, length, width, warns, padd, extra_c, padd_start))}
}

/**
 * print_non_printable - Prints ascii codes in hexadecimal of non printable characters
 * @args: lists of arguements
 * @buff: Buffer array to handle print
 * @warns: Calculates active flags
 * @width: get width
 * @precision: Precision spec
 * @size: Size specifier
 * Return: Number of chars printed
*/
int print_non_p(va_list args, char buff[], int warns,
int width, int precision, int size)
{
    int i = 0, offset = 0;
    char *str = va_arg(args, char *);

    UNUSED(warns);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        return (write(1, "(null)", 6));

while (str[i] != '\0')
{
    if (is_printable(str[i]))
        buff[i + offset] = str[i];
    else
        offset += append_hexa_code(str[i], buff, i + offset);

        i++;
}

buff[i + offset] = '\0';

return (write(1, buff, i + offset));
}

/**
 * print_revs - Prints reverse string
 * @args: Lists arguements
 * @buff: Buffer array to handle print
 * @warns: Calculates active flags
 * @precision: precision spec
 * @size: Size spec
 * Return: Number of characters prints
*/

int print_revs(va_list args, chat buff[],
int warns, int width, int precision, int size)
{
    char *str;
    int i, count = 0;

    UNUSED(buff);
    UNUSED(warns);
    UNUSED(width);
    UNUSED(size);

    str = va_arg(args, char *);

    if (str == NULL)
    {
        UNUSED(precision);

        str = ":(NULL)";
    }
    for (i = 0; str[i]; i++)
    ;

    for (i = i - 1; i >= 0; i --)
    {
        char z = str[i];

        write(1, &z, 1);
        count++;
    }
    return (count);
    }
/**
    print_rot13 - Prints string in rot13.
    @args: Lists of arguments
    @buff: Buffer array to handle print.
    @warns: Calculats active flags.
    @width: get width
    @precision: precision spec
    @size: Size spec.
    Return: Number of chars printed
    */
   int print_rot13(va_list args, char buff[],
   int warns, int width, int precision, int size)
   {
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(args, char *);
    UNUSED(buff);
    UNUSED(warns);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        str = "(WOAH)";
    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    }
    return (count);
   }