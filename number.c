/**
 * convert - convert a number to a string representation in the given base
 * @num: the number to convert
 * @base: the base to convert the number to
 * @flags: flags to modify conversion behavior
 * @params: additional parameters for the conversion
 * Return: a pointer to the string representation of the number
 */
char *convert(long int num, int base, int flags, params_t *params)
{
  static char buffer[50];
  char sign = 0;
  char *ptr;
  unsigned long n = num;
  static const char *digits_lowercase = "0123456789abcdef";
  static const char *digits_uppercase = "0123456789ABCDEF";

  // Ignore unused parameter
  (void)params;

  // Determine sign of number
  if (!(flags & CONVERT_UNSIGNED) && num < 0)
  {
    n = -num;
    sign = '-';
  }

  // Determine digits for the conversion
  const char *digits = (flags & CONVERT_LOWERCASE) ? digits_lowercase : digits_uppercase;

  // Convert number to string representation in the given base
  ptr = &buffer[49];
  *ptr = '\0';
  do {
    *--ptr = digits[n % base];
    n /= base;
  } while (n != 0);

  // Add sign to the string representation if necessary
  if (sign)
    *--ptr = sign;

  return ptr;
}

/**
 * print_unsigned - prints an unsigned integer number
 * @ap: the argument pointer
 * @params: additional parameters for the conversion
 * Return: the number of bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
  unsigned long l;

  // Extract the argument based on the length modifier specified in the parameters
  if (params->l_modifier)
    l = (unsigned long)va_arg(ap, unsigned long);
  else if (params->h_modifier)
    l = (unsigned short int)va_arg(ap, unsigned int);
  else
    l = (unsigned int)va_arg(ap, unsigned int);

  // Set the "unsigned" flag in the parameters
  params->unsign = 1;

  // Convert the number to a string and print it
  return print_number(convert(l, 10, CONVERT_UNSIGNED, params), params);
}

/**
 * print_address - prints the address of a pointer
 * @ap: the argument pointer
 * @params: additional parameters for the conversion
 * Return: the number of bytes printed
 */
int print_address(va_list ap, params_t *params)
{
  unsigned long int n = va_arg(ap, unsigned long int);
  char *str;

  // Print "(nil)" if the pointer is NULL
  if (!n)
    return _puts("(nil)");

  // Convert the pointer address to a string representation in base 16 and add "0x" to the beginning
  str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
  *--str = 'x';
  *--str = '0';

  // Print the address string
  return print_number(str, params);
}
