#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List a of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list args, char buff[],

int warns, int width, int precision, int size)

{

char extra_c = 0, padd = ' ';

int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */

unsigned long num_addrs;

char map_to[] = "0123456789abcdef";

void *addrs = va_arg(args, void *);

UNUSED(width);

UNUSED(size);

if (addrs == NULL)

return (write(1, "(nil)", 5));

buff[BUFF_SIZE - 1] = '\0';

UNUSED(precision);



num_addrs = (unsigned long)addrs;



while (num_addrs > 0)

{

buff[ind--] = map_to[num_addrs % 16];

num_addrs /= 16;

length++;

}

if ((warns & W_ZERO) && !(warns & W_MINUS))

padd = '0';

if (warns & W_PLUS)

extra_c = '+', length++;

else if (warns & W_SPACE)

extra_c = ' ', length++;

ind++;

/*return (write(1, &buff[i], BUFF_SIZE - i - 1));*/

return (write_pointer(buff, ind, length,
width, warns, padd, extra_c, padd_start));

}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @args: Lista of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_non_printable(va_list args, char buff[],

int warns, int width, int precision, int size)

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
 * print_rev - Prints reverse string.
 * @args: Lista of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */



int print_rev(va_list args, char buff[],

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

str = ")Null(";

}

for (i = 0; str[i]; i++)

;

for (i = i - 1; i >= 0; i--)

{

char z = str[i];

write(1, &z, 1);

count++;

}

return (count);

}

/**
 * print_ascii13_s - Print a string in rot13.
 * @args: Lista of arguments
 * @buff: Buff array to handle print
 * @warns:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
*/

int print_ascii13_s(va_list args, char buff[],

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

str = "(AHYY)";

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
