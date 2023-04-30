Printf Project
This is an implementation of the printf function in C programming language. The printf function is used to print formatted output to the standard output stream (stdout). It takes a format string and a variable number of arguments, and produces output according to the format string.

This implementation of printf supports a subset of the conversion specifiers and flags that are defined in the C standard library. The supported conversion specifiers are %c, %s, %d, %i, %u, %o, %x, and %X. The supported flags are 0, -, +, ' ', and #. The supported length modifiers are hh, h, l, and ll. The behavior of the function is similar to the standard printf function, but there may be some differences in the output produced by the two functions.

Usage
The function is declared in the main.h header file, and it can be used in the same way as the standard printf function:

c
Copy code
#include "main.h"

int main(void)
{
    int i = 42;
    char *s = "hello, world";

    _printf("%d\n", i);     // prints "42\n"
    _printf("%s\n", s);     // prints "hello, world\n"
    _printf("%x\n", i);     // prints "2a\n"
    _printf("%#x\n", i);    // prints "0x2a\n"
    _printf("%-10s\n", s);  // prints "hello, world\n"
    _printf("%010d\n", i);  // prints "0000000042\n"

    return (0);
}
Supported Conversion Specifiers
The following conversion specifiers are supported by this implementation of printf:

%c: prints a single character
%s: prints a null-terminated string
%d, %i: prints a signed decimal integer
%u: prints an unsigned decimal integer
%o: prints an unsigned octal integer
%x: prints an unsigned hexadecimal integer in lowercase
%X: prints an unsigned hexadecimal integer in uppercase
Supported Flags
The following flags are supported by this implementation of printf:

0: pads with zeros instead of spaces
-: left-aligns the output within the field width
+: prints a sign (+ or -) before a signed number
' ': prints a space before a positive number (ignored if the + flag is present)
#: adds a prefix (0, 0x, or 0X) to the output
Supported Length Modifiers
The following length modifiers are supported by this implementation of printf:

hh: indicates that a following d, i, o, u, x, or X conversion specifier applies to a signed char or unsigned char argument
h: indicates that a following d, i, o, u, x, or X conversion specifier applies to a short int or unsigned short int argument
l: indicates that a following d, i, o, u, x, or X conversion specifier applies to a long int or unsigned long int argument
ll: indicates that a following d, i, o, u, x, or X conversion specifier applies to a long long int or