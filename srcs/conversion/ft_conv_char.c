#include "ft_printf.h"

int ft_conv_char(int c, t_opts opts)
{
    int len;

    len = 0;
    if (c == '\0')
        len = 1;
    while (opts.wdt > 1 && !opts.flags.minus)
    {
        ft_putchar(' ');
        opts.wdt--;
        len++;
    }
    ft_putchar(c);
    while (opts.wdt > 1 && opts.flags.minus)
    {
        ft_putchar(' ');
        opts.wdt--;
        len++;
    }
    return (len);
}
