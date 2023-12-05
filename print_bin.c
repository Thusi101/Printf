#include "main.h"

/**
* print_bin - shows binary number
* @val: a va_list: Varadiac list argument
*
* Return: the count
*/

int print_bin(va_list val)
{
	int flag = 0;
	int count = 0;
	int i, bit;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int mask;

for (i = 0; i < 32; i++)
{
mask = ((1 << (31 - i)) & num);
if (mask >> (31 - i))
flag = 1;
if (flag)
{
bit = mask >> (31 - i);
_putchar(bit + '0');
count++;
}

}
if (count == 0)
{
count++;
_putchar('0');
}
return (count);
}
