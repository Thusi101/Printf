#define MAIN_H
#ifndef MAIN_H
#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/*Warns*/
#define W_MINUS 1
#define W_PLUS 2
#define W_ZERO 4
#define W_HASH 8
#define W_SPACE 16

/*Dimensions*/
#define D_SHORT 1
#define D_LONG 2

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * struct format - Structure operation.
 * @ph: Symbol of format conversion
 * @funct: Function of printf
 */
typedef struct format
{
	char *ph;
	int (*funct)(va_list, char[], int);
} convert;

/**
 * typedef struct ph ph_m - struct op
 *
 * @ph: Symbol of format
 * @ph_m: associated function
 */
typedef struct ph ph_m;

int *_strcpy(char *dest, char src);
int print_pointer(va_list val, char buff[], int warns, int width, int precision, int size);
int printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int warns, int width, int precision, int size);
int handle_write_c(char c, char buff[], int warns, int width, int precision, int size);
int write_number(int is_positive, int ind, char buff[], int warns, int width, int precision, int size);
int write_num(int ind, char buff[], int warns, int width, int precision, int size);
int write_pointer(char buff[], int ind, int length, int width, int warns, char padd, char extra_c, int padd_start);
int print_hex_extra(va_list val, char buff[], int warns, int width, int precision, int size);
int _strlenc(const char *s);
int print_HEX_extra(va_list val, char map_to[], char buff[], int warns, char warn_ch, int width, int precision, int size);
int print_c(va_list val, char buff[], int warns, int width, int precision, int size);
int print_s(va_list val, char buff[], int warns, int width, int precision, int size);
int print_p(va_list val, char buff[], int warns, int width, int precision, int size);
int print_hex(va_list val, char buff[], int warns, int width, int precision, int size);
int print_exc_string(va_list val);
int print_oct(va_list val, char buff[], int warns, int width, int precision, int size);
int print_bin(va_list val, char buff[], int warns, int width, int precision, int size);
int print_52(void);
int print_d(va_list args);
int print_i(va_list args, char buff[], int warns, int width, int precision, int size);
int print_non_p(va_list args, char buff[], int warns, int width, int precision, int size); /*prints non printiable chars*/
int print_rot13(va_list args, char buff[], int warns, int width, int precision, int size);/* print string in rot 13*/
int print_revs(va_list args, chat buff[], int warns, int width, int precision, int size);/* prints string in revers*/
int print_unsigned(va_list args);
int write_unsigned(int is_negative, int ind, char buff[], int warns, int width, int precision, int size);
int _strlen(char *s);
int rev_string(char *s);
int putchar(int c);
int get_width(const char *ph, int *i);
int get_warns(const char *ph, int *i, va_list list);
int get_precision(const char *ph, int *i, va_list list);
int get_size(const char *format, int *i);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digital(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H*/
