#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * checkErr - goes through the loop and check for errors
 * @format: string to be searched for errors
 * Return: zero if code runs successfully
 */
int checkErr(const char *format)
{
int i;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
/** if after the % sign is a space return */
case ' ':
return (-1);
break;
/** if after the % sign is a null char return */
case '\0':
return (-1);
break;
}
}
}
return (0);
}


/**
 * _printf - sends formatted string to stdout
 * @format: string to searched to for format specifier
 * @...: parameters to replace format specifiers by
 * Return: returns the length of the string
 */

int _printf(const char *format, ...)
{
int i, count = 0;
char *str;
va_list list;
va_start(list, format);
checkErr(format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '\\')
{i++;
if (format[i] == 'n')
{putchar('\n');
}
}
if (format[i] == '%')
{i++;
switch (format[i])
{case 'c':
putchar(va_arg(list, int));
count++;
break;
case 's':
str = va_arg(list, char *);
fputs(str, stdout);
count += strlen(str);
break;
case '%':
putchar('%');
count++;
break;
default:
putchar(format[i]);
count++;
break;
}
}
else
{putchar(format[i]);
count++;
}
} return (count);
}


