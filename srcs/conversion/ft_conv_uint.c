#include "ft_printf.h"

static char *ft_prc_uint(char *s, int len, t_opts opts)
{
    char    *new;
    int     new_len;

    new = ft_strdup(s);
    new[opts.prc] = '\0';
    if (opts.prc > len)
    {
        ft_memset(new, '0', opts.prc);
        new_len = opts.prc - len;
        ft_strncpy(&new[new_len], s, len);
    }
    free(s);
    return (new);
}

static char *ft_wdt_uint(char *s, int len, t_opts opts)
{
    char    *new;
    int     new_len;

    new = ft_strdup(s);
    ft_memset(new, ' ', opts.wdt);
    new[opts.prc] = '\0';
    if (opts.flags.zero && !opts.flags.minus)
        ft_memset(new, '0', opts.wdt);
    if (opts.flags.minus >= 1)
        ft_strncpy(new, s, len);
    else
    {
        new_len = opts.wdt - len;
        ft_strncpy(&new[new_len], s, len);
    }
    return (new);
}

int ft_conv_uint(unsigned int n, t_opts opts)
{
    char    *s;
    char    *new;
    int     len;

    s = ft_itoa_unsigned(n);
    len = ft_strlen_int(s);
    if (opts.prc > len)
        s = ft_prc_uint(s, len, opts);
    if (opts.wdt > len)
    {
        new = ft_wdt_uint(s, len, opts);
        len = ft_putstr_size(new);
        free(new);
    }
    else
        len = ft_putstr_size(s);
    free(s);
    return (len);
}