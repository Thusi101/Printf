#include "main.h"
#include <unistd.h>

/**
 * _putchar - to inscribe character c to standard output
 * @c: Character to be inlayed
 *
 * Return: if successful, return 1.
 * if unsuccessful, return -1, erron is set appropriately.
 */

int _putchar(char c)
{
	return write(1, &c, 1);
}
