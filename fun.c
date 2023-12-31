#include "main.h"

/**
 * print_char - Prints a char
 * @args: List a of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_char(va_list args, char buff[],

int warns, int width, int precision, int size)

{

char c = va_arg(args, int);

return (handle_write_char(c, buff, warns, width, precision, size));

}

/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_string(va_list args, char buff[],

int warns, int width, int precision, int size)

{

int length = 0, i;

char *str = va_arg(args, char *);

UNUSED(buff);
UNUSED(warns);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)

{

str = "(null)";

if (precision >= 6)

str = "   ";

}

while (str[length] != '\0')

length++;

if (precision >= 0 && precision < length)

length = precision;

if (width > length)

{

if (warns & W_MINUS)

{

write(1, &str[0], length);

for (i = width - length; i > 0; i--)

write(1, " ", 1);

return (width);

}

else

{

for (i = width - length; i > 0; i--)

write(1, " ", 1);

write(1, &str[0], length);

return (width);

}

}

return (write(1, str, length));

}

/**
 * print_percent - Prints a percent sign
 * @args: Lista of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_percent(va_list args, char buff[],
int warns, int width, int precision, int size)

{

UNUSED(args);
UNUSED(buff);
UNUSED(warns);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

return (write(1, "%%", 1));

}

/**
 * print_int - Print int
 * @args: Lista of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_int(va_list args, char buff[],

int warns, int width, int precision, int size)

{

int i = BUFF_SIZE - 2;

int is_negative = 0;

long int n = va_arg(args, long int);

unsigned long int num;

char extra_c = ' ';
char padd = ' ';
int ind = 0;

n = convert_size_number(n, size);

if (n == 0)

buff[i--] = '0';

buff[BUFF_SIZE - 1] = '\0';

num = (unsigned long int)n;

if (n < 0)

{

num = (unsigned long int)((-1) * n);

is_negative = 1;

}

while (num > 0)

{

buff[i--] = (num % 10) + '0';

num /= 10;

}

i++;

return write_num_n(is_negative, ind, buff, width, precision, size, padd);


/**
 * print_binary - Prints an unsigned number
 * @args: Lista of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list args, char buff[],
int warns, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

UNUSED(buff);
UNUSED(warns);
UNUSED(width);
UNUSED(precision);
UNUSED(size);



n = va_arg(args, unsigned int);

m = 2147483648; /* (2 ^ 31) */

a[0] = n / m;

for (i = 1; i < 32; i++)

{

m /= 2;

a[i] = (n / m) % 2;

}

for (i = 0, sum = 0, count = 0; i < 32; i++)

{

sum += a[i];

if (sum || i == 31)

{

char z = '0' + a[i];

write(1, &z, 1);

count++;

}

}

return (count);

}

}
