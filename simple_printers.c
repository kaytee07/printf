/**

print_from_to - prints a range of char addresses excluding a specific address
@start: starting address of the range to print
@stop: stopping address of the range to print
@except: address to exclude from the range
Return: number of bytes printed
*/
int print_from_to(char *start, char *stop, char *except)
{
int sum = 0;
while (start <= stop)
{
if (start != except)
sum += _putchar(*start);
start++;
}

return sum;
}

/**

print_rev - prints a given string in reverse order
@ap: string to print
@params: the parameters struct (not used)
Return: number of bytes printed
*/
int print_rev(va_list ap, params_t *params)
{
char *str = va_arg(ap, char *);
int len = 0, sum = 0;
(void)params;

if (str)
{
while (str != '\0') / calculate length of string /
{
len++;
str++;
}
while (len > 0) / print the string in reverse order */
{
str--;
sum += _putchar(*str);
len--;
}
}

return sum;
}

/**

print_rot13 - prints a given string in rot13 encoding
@ap: string to print
@params: the parameters struct (not used)
Return: number of bytes printed
*/
int print_rot13(va_list ap, params_t *params)
{
char *a = va_arg(ap, char *);
int i = 0, count = 0;
(void)params;

while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
{
int index = a[i] - 65;
if (a[i] >= 'a' && a[i] <= 'z') /* convert lowercase to uppercase */
index += 32;
count += _putchar("NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm"[index]);
}
else
{
count += _putchar(a[i]);
}
i++;
}

return count;
}
