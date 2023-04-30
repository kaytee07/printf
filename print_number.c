#include "main.h"

ng.
* @s: The string to get the length of.
 *
* Return: The length of the string.
 */
int _strlen(char *s)
{
  int length = 0;

  while (*s++)
    length++;

  return (length);
}

/**
 * print_number - Prints a number with options.
 * @str: The/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * _strlen - Returns the length of a stri base number as a string.
 * @params: The parameter struct.
 *
 * Return: The number of characters printed.
 */
int print_number(char *str, params_t *params)
{
    unsigned int i = _strlen(str);
    int neg = (!params->unsign && *str == '-');

    // Check for special cases where the string should be empty.
    if (!params->precision && *str == '0' && !str[1])
        str = "";

    // Remove negative sign from string and adjust string length.
    if (neg)
    {
        str++;
        i--;
    }

    // Add leading zeros to string if necessary.
    if (params->precision != UINT_MAX)
    {
        while (i++ < params->precision)
            *--str = '0';
    }

    // Add negative sign back to string if necessary.
    if (neg)
        *--str = '-';

    // Choose the appropriate print function based on flags.
    if (!params->minus_flag)
        return (print_number_right_shift(str, params));
    else
        return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - Prints a number with options, right-shifted.
 * @str: The base number as a string.
 * @params: The parameter struct.
 *
 * Return: The number of characters printed.
 */
ar == '0')
n += _putchar('-');
if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
  n += _putchar('+');
 else if (!params->plus_flag && params->space_flag && !neg2 && !params->unsign && params->zero_flag)
   n += _putchar(' ');

while (i++ < pint print_number_right_shift(char *str, params_t *params)
{
unsigned int n = 0, neg, neg2, i = _strlen(str);
char pad_char = ' ';
// Set padding character to zero if zero_flag is set and minus_flag is not
if (params->zero_flag && !params->minus_flag)
pad_char = '0';

// Check if the number is negative and adjust variables accordingly
neg = neg2 = (!params->unsign && *str == '-');
if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
str++;
else
neg = 0;

// Check if the plus_flag or space_flag is set and adjust the width accordingly
if ((params->plus_flag && !neg2) || (!params->plus_flag && params->space_flag && !neg2))
i++;

// Print the negative sign if necessary and pad the number with the chosen padding character
if (neg && pad_charams->width)
n += _putchar(pad_char);

// Print the negative sign if necessary and the number itself
if (neg && pad_char == ' ')
n += _putchar('-');
if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
n += _putchar('+');
else if (!params->plus_flag && params->space_flag && !neg2 && !params->unsign && !params->zero_flag)
n += _putchar(' ');

n += _puts(str); // Print the number string itself
return (n);
}

/**
 * print_number_left_shift - prints a number with options, left-justified
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: number of characters printed
 */
int print_number_left_shift(char *str, params_t *params)
{
  unsigned int n = 0, neg, neg2, i = _strlen(str);
  char pad_char = ' ';

  if (params->zero_flag && !params->minus_flag)
    pad_char = '0';
  
  neg = neg2 = (!params->unsign && *str == '-');
  if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
    str++, i--;
  else
    neg = 0;

  if (params->plus_flag && !neg2 && !params->unsign)
    n += _putchar('+'), i++;
  else if (params->space_flag && !neg2 && !params->unsign)
    n += _putchar(' '), i++;

  n += _puts(str);

  while (i++ < params->width)
    n += _putchar(pad_char);

  return (n);
}
