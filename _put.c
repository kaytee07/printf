#include "main.h"

/**
 * _puts - Prints a string with a newline character.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int _puts(char *str)
{
        char *a = str;

        while (*str)
                _putchar(*str++);
        _putchar('\n');
        return (str - a + 1);
}

/**
 * _putchar - Writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1 is returned and errno is set appropriately.
 */
int _putchar(int c)
{
        static int i;
        static char buf[OUTPUT_BUF_SIZE];

        if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
        {
                write(1, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}
