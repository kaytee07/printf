#include "main.h"

/**
 * get_specifier - finds the function pointer for the given format specifier
 * @s: the format string
 *
 * Return: pointer to function that handles the specifier or NULL if not found
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
  specifier_t specifiers[] = {
    {"c", print_char},
    {"d", print_int},
    {"i", print_int},
    {"s", print_string},
    {"%", print_percent},
    {"b", print_binary},
    {"o", print_octal},
    {"u", print_unsigned},
    {"x", print_hex},
    {"X", print_HEX},
    {"p", print_address},
    {"S", print_S},
    {"r", print_rev},
    {"R", print_rot13},
    {NULL, NULL}
  };
  int i = 0;

  while (specifiers[i].specifier)
  {
    if (*s == specifiers[i].specifier[0])
    {
      return (specifiers[i].f);
    }
    i++;
  }
  return (NULL);
}

/**
 * get_print_func - finds the function pointer for the given format specifier
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
  int (*f)(va_list, params_t *) = get_specifier(s);

  if (f)
    return (f(ap, params));
  return (0);
}

/**
 * get_flag - finds the flag specified in the format string
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: 1 if flag was found, 0 otherwise
 */
int get_flag(char *s, params_t *params)
{
  switch (*s)
  {
    case '+':
      params->plus_flag = 1;
      return (1);
    case ' ':
      params->space_flag = 1;
      return (1);
    case '#':
      params->hashtag_flag = 1;
      return (1);
    case '-':
      params->minus_flag = 1;
      return (1);
    case '0':
      params->zero_flag = 1;
      return (1);
    default:
      return (0);
  }
}

/**
 * get_modifier - finds the modifier specified in the format string
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: 1 if modifier was found, 0 otherwise
 */
int get_modifier(char *s, params_t *params)
{
  switch (*s)
  {
    case 'h':
      params->h_modifier = 1;
      return (1);
    case 'l':
      params->l_modifier = 1;
      return (1);
    default:
      return (0);
  }
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
  int d = 0;

  if (*s == '*')
  {
    d = va_arg(ap, int);
    s++;
  }
  else
  {
    while (_isdigit(*s))
      d = d * 10 + (*s++ - '0');
  }

  params->width = d;
  return (s);
}
