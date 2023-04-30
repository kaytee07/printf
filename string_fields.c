/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
    int precision = 0;
    char *p_start = p;

    if (*p != '.')
        return p_start;

    p++;

    if (*p == '*')
    {
        precision = va_arg(ap, int);
        p++;
    }
    else
    {
        while (_isdigit(*p))
        {
            precision = precision * 10 + (*p - '0');
            p++;
        }
    }

    params->precision = precision;
    return p;
}
