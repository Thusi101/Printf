#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define W_MINUS 1
#define W_PLUS 2
#define W_ZERO 4
#define W_HASH 8
#define W_SPACE 16
#define D_LONG 2
#define D_SHORT 1

/**
 * struct frmt - Struct oroperties
 * @frmt: The format.
 * @fnc: The function associated.
*/

struct frmt
{
char frmt;
int (*fnc)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct frmt frmt_t - Struct op
 * @frmt: The format.
 * @fm_t: The function associated.
 */

typedef struct frmt frmt_t;



int _printf(const char *format, ...);

int handle_print(const char *frmt, int *i,

va_list list, char buff[], int warns, int width, int precision, int size);



/****************** FUNCTIONS ******************/



/* Funtions to print chars and strings */

int print_char(va_list args, char buff[],

int warns, int width, int precision, int size);

int print_string(va_list args, char buff[],

int warns, int width, int precision, int size);

int print_percent(va_list args, char buff[],

int warns, int width, int precision, int size);



/* Functions to print numbers */

int print_int(va_list args, char buff[],

int warns, int width, int precision, int size);

int print_binary(va_list args, char buff[],

int warns, int width, int precision, int size);

int print_unsigned(va_list args, char buff[],

int warns, int width, int precision, int size);

int print_octal(va_list args, char buff[],

int warns, int width, int precision, int size);

int print_hexa_D(va_list args, char buff[],

int warns, int width, int precision, int size);

int print_hexa_upper(va_list args, char buff[],

int warns, int width, int precision, int size);



int print_hexa(va_list args, char map_to[],

char buff[], int warns, char warns_ch, int width, int precision, int size);



/* Function to print non printable characters */

int print_non_printable(va_list args, char buff[],

int warns, int width, int precision, int size);



/* Funcion to print memory address */

int print_pointer(va_list args, char buff[],

int warns, int width, int precision, int size);



/* Funciotns to handle other specifiers */

int get_warns(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);



/*Function to print string in reverse*/

int print_rev(va_list args, char buff[],

int warns, int width, int precision, int size);



/*Function to print a string in rot 13*/

int print_ascii13_s(va_list args, char buff[],

int warns, int width, int precision, int size);



/* width handler */

int handle_write_char(char c, char buff[],

int warns, int width, int precision, int size);

int write_num(int is_positive, int ind, char buff[],

int warns, int width, int precision, int size);

int write_num(int ind, char bff[], int warns, int width, int precision,

int length, char padd, char extra_c);

int write_pointer(char buff[], int ind, int length,

int width, int warns, char padd, char extra_c, int padd_start);



int write_unsgnd(int is_negative, int ind,

char buff[],

int warns, int width, int precision, int size);

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);



long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
