#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#define BUFF_SIZE 1024

void print_out_buff(char buff[],int *buff_ind);

/**
 * m_printf - printf function
 * @in_format: format.
 * @return: Total characters printed.
 */

int printf_out(const char *in_format, ...)
{

