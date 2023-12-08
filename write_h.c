#include "main.h"

/**
* handle_write_c - Prints string
* @c: Char types
* @buff: Buffer array to handle print
* @warns: Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: size specifier
*
* Return: Number of chars printed.
*/
int handle_write_c(char c, char buff[], int warns,
		int width, int precision, int size);
{
/* char is stored at left and paddind at buff's right*/
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (warns & W_ZERO)
		padd = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUFF_SIZE - i - 2] = padd;
		if (warns & W_MINUS)
			return (write(1, &buff[0], 1) + write(1, &buff[BUFF_SIZE - i - 1],
						width - 1));
	}
	else
	{
		return (write(1, &buff[BUFF_SIZE - i - 1],
					width - 1) + write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

/**
* write_number - prints a string
* @is_negative: Lists of arguments
* @ind: char types.
* @buff: buffer arrau to handle print
* @warns: calculates active flags
* @width: get width
* @precision: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/

int write_number(int is_negative, int ind, char buff[],
		int warns, int width, int precision, int size)
{
    unsigned int m, s, i, sum;
    unsigned int c[32];
    int count;

    UNUSED(buff);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    m = va_arg(val, unsigned int);
    s = 2147483648; /* (2 ^ 31)*/
    c[0] = m / s;
    for (i = 1; i < 32; i++)
    {
        s /= 2;
        c[i] = (m / s) % 2;
    }
    for (i = 0, sum = 0, count = 0; i < 32; i++)
    {
        sum += c[i];
        if (sum || i == 31)
        {
            char x = '0' + a[i];

            write(1, &x, 1);
            count++;
        }
    }
    return (count);

}
