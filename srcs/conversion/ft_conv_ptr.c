#include "ft_printf.h"

static char *ft_wdt_ptr(char *s, int len, t_opts opts)
{
    char    *new;
    int     new_len;

    new = ft_strdup(s);
    ft_memset(new, ' ', opts.wdt);
    new[opts.wdt] = '\0';
    if (opts.flags.minus >= 1)
        ft_strncpy(new, s, len);
    else
    {
        new_len = opts.wdt - len;
        ft_strncpy(&new[new_len], s, len);
    }
    free(s);
    return (new);
}

int ft_conv_ptr(unsigned long n, t_opts opts)
{
    char    *s;
    int     len;

    s = ft_itoa_ptr(n);
    s = ft_insert_str(s, "0x", 0);
    len = ft_strlen_int(s);
    if (opts.wdt > len)
        s = ft_wdt_ptr(s, len, opts);
    len = ft_strlen_int(s);
    ft_putstr(s);
    free(s);
    return (len);
}
