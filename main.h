#define PRINTF_H
#ifndef PRINTF_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct format - Printf Magic.
 * @ph: Symbol of conversion
 * @function: Function of printf
 */
typedef struct format
{
	char *ph;
	int (function)();
} convert;

/**
 * @brief: copy of string
 *
 * @param_dest: parameter destination
 * @param_src: parameter source
 * @return: length of copy.
 */

int *_strcpy(char *dest, char src);
int print_pointer(va_list val);
int printf(const char *format, ...);
int print_hex_extra(unsigned long int num);
int _strlenc(const char *s);
int print_HEX_extra(unsigned int num);
int print_c(va_list val);
int print_s(va_list val);
int print_HEX(va_list val);
int print_hex(va_list val);
int print_exc_string(va_list val);
int print_oct(va_list val);
int print_bin(va_list val);
int print_52(void);
int print_d(va_list args);
int print_i(va_list args);
int print_rot13(va_list args);
int print_revs(va_list args);
int print_unsigned(va_list args);
int _strlen(char *s);
int rev_string(char *s);
int putchar(char c);

#endif
