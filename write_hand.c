#include "main.h"
#include <stdarg.h>

/**
 * handle_write_char - Prints a string
 * @c: char args.
 * @buff: Buff array to handle print
 * @warns: Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.

*/

int handle_write_char(char c, char buff[],

int warns, int width, int precision, int size)

{
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

return (write(1, &buff[0], 1) +

write(1, &buff[BUFF_SIZE - i - 1], width - 1));

else

return (write(1, &buff[BUFF_SIZE - i - 1], width - 1) +

write(1, &buff[0], 1));

}

return (write(1, &buff[0], 1));

}

/**
 * write_num - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char args.
 * @buff: Buff array to handle print
 * @warns: Calculates active flags
 * @width: Get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int write_num_n(int is_negative, int ind, char buff[], char padd,
		int warns, int width, int precision, int size)
{

int length = BUFF_SIZE - ind - 1;
char padd = ' ';
char extra_ch = 0;

if (is_negative)

extra_ch = '-';

UNUSED(size);

if ((warns & W_ZERO) && !(warns & W_MINUS))

padd = '0';

else if (warns & W_PLUS)

extra_ch = '+';

else if (warns & W_SPACE)

extra_ch = ' ';


return (write_num(ind, buff, warns, width, precision,

length, padd, extra_ch));

}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buff: Buff
 * @warns: Flags
 * @width: width
 * @precision: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars.
 */

int write_num(int ind, char buff[],

int warns, int width, int precision,

int length, char padd, char extra_c)

{

int i, padd_start = 1;


if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && width == 0)

return (0); /* printf(".0d", 0)  no char is printed */

if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')

buff[ind] = padd = ' ';
if (precision > 0 && precision < length)

padd = ' ';

while (precision > length)

buff[--ind] = '0', length++;

if (extra_c != 0)

length++;

if (width > length)

{

for (i = 1; i < width - length + 1; i++)

buff[i] = padd;

buff[i] = '\0';

if (warns & W_MINUS && padd == ' ')
{

if (extra_c)

buff[--ind] = extra_c;

return (write(1, &buff[ind], length) + write(1, &buff[1], i - 1));

}

else if (!(warns & W_MINUS) && padd == ' ')
{

if (extra_c)

buff[--ind] = extra_c;

return (write(1, &buff[1], i - 1) + write(1, &buff[ind], length));

}

else if (!(warns & W_MINUS) && padd == '0')
{

if (extra_c)

buff[--padd_start] = extra_c;

return (write(1, &buff[padd_start], i - padd_start) +

write(1, &buff[ind], length - (1 - padd_start)));

}

}

if (extra_c)

buff[--ind] = extra_c;

return (write(1, &buff[ind], length));

}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buff
 * @buff: Array of chars
 * @warns: Warns specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int ind,

char buff[],

int warns, int width, int precision, int size)

{

int length = BUFF_SIZE - ind - 1, i = 0;

char padd = ' ';

UNUSED(is_negative);

UNUSED(size);

if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')

return (0); /* printf(".0d", 0)  no char is printed */



if (precision > 0 && precision < length)

padd = ' ';



while (precision > length)

{

buff[--ind] = '0';

length++;

}



if ((warns & W_ZERO) && !(warns & W_MINUS))

padd = '0';



if (width > length)

{

for (i = 0; i < width - length; i++)

buff[i] = padd;



buff[i] = '\0';



if (warns & W_MINUS)
{

return (write(1, &buff[ind], length) + write(1, &buff[0], i));

}
else
{

return (write(1, &buff[0], i) + write(1, &buff[ind], length));

}

}



return (write(1, &buff[ind], length));

}



/**
 * write_pointer - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buff
 * @length: Length of number
 * @width: Wwidth specifier
 * @warns: Warns specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 * Return: Number of written chars.
*/

int write_pointer(char buff[], int ind, int length,

int width, int warns, char padd, char extra_c, int padd_start)

{

int i;


if (width > length)

{

for (i = 3; i < width - length + 3; i++)

buff[i] = padd;

buff[i] = '\0';

if (warns & W_MINUS && padd == ' ')

{

buff[--ind] = 'x';

buff[--ind] = '0';

if (extra_c)

buff[--ind] = extra_c;

return (write(1, &buff[ind], length) + write(1, &buff[3], i - 3));

}

else if (!(warns & W_MINUS) && padd == ' ')
{

buff[--ind] = 'x';

buff[--ind] = '0';

if (extra_c)

buff[--ind] = extra_c;

return (write(1, &buff[3], i - 3) + write(1, &buff[ind], length));

}

else if (!(warns & W_MINUS) && padd == '0')
{

if (extra_c)

buff[--padd_start] = extra_c;

buff[1] = '0';

buff[2] = 'x';

return (write(1, &buff[padd_start], i - padd_start) +

write(1, &buff[ind], length - (1 - padd_start) - 2));

}

}

buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
buff[--ind] = extra_c;

return (write(1, &buff[ind], BUFF_SIZE - ind - 1));

}
