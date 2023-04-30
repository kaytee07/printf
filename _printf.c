#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: the format string to print
 * @...: the optional arguments to insert into the format string
 *
 * Return: the number of characters printed, or -1 if an error occurs
 */
int _printf(const char *format, ...)
{
    va_list args;  // initialize the variable argument list
    int count = 0; // initialize the character count

    // Check for invalid input
    if (!format)
        return (-1);

    // Iterate through the format string and process each format specifier
    va_start(args, format);
    while (*format)
    {
        // If the current character is not a format specifier, print it
        if (*format != '%')
        {
            _putchar(*format++);
            count++;
            continue;
        }

        // Parse the format specifier
        format++;
        switch (*format)
        {
            case 'c':
                count += _putchar(va_arg(args, int));
                break;
            case 's':
                count += _puts(va_arg(args, char *));
                break;
            case 'd':
            case 'i':
                count += print_integer(args);
                break;
            case 'u':
                count += print_unsigned(args);
                break;
            case 'o':
                count += print_octal(args);
                break;
            case 'x':
                count += print_hex(args, 0);
                break;
            case 'X':
                count += print_hex(args, 1);
                break;
            case '%':
                _putchar('%');
                count++;
                break;
            default:
                _putchar('%');
                count++;
                _putchar(*format);
                count++;
                break;
        }

        format++;
    }

    va_end(args); // clean up the variable argument list
    return (count); // return the total character count
}
