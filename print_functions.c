#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
  params->unsign = 0;

  params->plus_flag = 0;
  params->space_flag = 0;
  params->hashtag_flag = 0;
  params->zero_flag = 0;
  params->minus_flag = 0;

  params->width = 0;
  params->precision = UINT_MAX;

  params->h_modifier = 0;
  params->l_modifier = 0;
  (void)ap;
}

/**
 * print_unsigned - prints unsigned int
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_unsigned(va_list ap, params_t *params)
{
  unsigned long l;

  if (params->l_modifier)
   l = va_arg(ap, unsigned long);
  else if (params->h_modifier)
   l = (unsigned short int)va_arg(ap, unsigned int);
  else
   l = (unsigned int)va_arg(ap, unsigned int);
  params->unsign = 1;
  return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_octal - prints octal
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_octal(va_list ap, params_t *params)
{
  unsigned long l;

  if (params->l_modifier)
   l = va_arg(ap, unsigned long);
  else if (params->h_modifier)
   l = (unsigned short int)va_arg(ap, unsigned int);
  else
   l = (unsigned int)va_arg(ap, unsigned int);
  return (print_number(convert(l, 8, 0, params), params));
}

/**
 * print_hex - prints hex
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_hex(va_list ap, params_t *params)
{
  unsigned long l;

  if (params->l_modifier)
   l = va_arg(ap, unsigned long);
  else if (params->h_modifier)
   l = (unsigned short int)va_arg(ap, unsigned int);
  else
   l = (unsigned int)va_arg(ap, unsigned int);
  return (print_number(convert(l, 16, 0, params), params));
}

/**
 * print_hex_upper - prints uppercase hex
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_hex_upper(va_list ap, params_t *params)
{
  unsigned long l;

  if (params->l_modifier)
   l = va_arg(ap, unsigned long);
  else if (params->h_modifier)
   l = (unsigned short int)va_arg(ap, unsigned int);
  else
   l = (unsigned int)va_arg(ap, unsigned int);
  return (print_number(convert(l, 16, 1, params), params));
}

/**
 * print_address - prints an address
 * @ap: the va_list containing the address as an unsigned long
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_address(va_list ap, params_t *params)
{
  unsigned long addr = va_arg(ap, unsigned long);
  char hex_digits[] = "0123456789abcdef";
  char hex_str[sizeof(void *) * 2 + 3];  // enough space for a pointer in hex format
  int i, n = 0;

  // convert the address to a string of hexadecimal digits
  hex_str[0] = '0';
  hex_str[1] = 'x';
  for (i = sizeof(void *) * 2 - 1; i >= 0; i--) {
    hex_str[i + 2] = hex_digits[addr & 0xf];
    addr >>= 4;
  }
  hex_str[sizeof(void *) * 2 + 2] = '\0';

  // apply the format flags
  params->hashtag_flag = 1;
  params->length_modifier = LENGTH_L;
  params->specifier = SPECIFIER_UNSIGNED_HEX;

  // print the converted value with the appropriate format
  n += print_number(hex_str, params);

  return n;
}
