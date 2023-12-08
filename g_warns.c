#include "main.h"

/**
 * get_warns - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Warns:
 */

int get_warns(const char *format, int *i)

{

/* - + 0 # ' ' */

int j, curr_i;

int warns = 0;

const char WARNS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

const int WARNS_ARR[] = {W_MINUS, W_PLUS, W_ZERO, W_HASH, W_SPACE, 0};

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)

{
for (j = 0; WARNS_CH[j] != '\0'; j++)

if (format[curr_i] == WARNS_CH[j])

{

warns |= WARNS_ARR[j];

break;

}

if (WARNS_CH[j] == 0)

break;

}

*i = curr_i - 1;

return (warns);

}
