#include "ft_printf.h"

static char    *ft_get_hex(int upper)
{
    if (upper == 1)
        return ("0X");
    else
        return ("0x");
}

static char *ft_prc_hex(char *s, int len, int upper, t_opts opts)
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
        if (opts.flags.sharp >= 1)
            new = ft_insert_str(new, ft_get_hex(upper), 0);
    }
    free(s);
    return (new);
}

static char *ft_wdt_hex(char *s, int len, t_opts opts)
{
    char    *new;
    int     new_len;

    new = ft_strdup(s);
    if (opts.flags.sharp && opts.flags.zero)
        opts.wdt -= 2;
    ft_memset(new, ' ', opts.wdt);
    new[opts.wdt] = '\0';
    if (opts.flags.zero && !opts.flags.minus)
        ft_memset(new, '0', opts.wdt);
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

static char *ft_opts_hex(char *s, int len, int upper, t_opts opts)
{
    char    *new;

    if (s[len - 1] == '0' && opts.flags.dot && !opts.prc && opts.wdt)
        ft_memset(s, ' ', len);
    if (!opts.prc && !opts.wdt && !opts.flags.zero && opts.flags.sharp
        && !(s[0] == '0' && s[1] == '\0') && !opts.flags.dot)
        new = ft_strjoin(ft_get_hex(upper), s);
    else
        return (s);
    free(s);
    return (new);
}

int ft_conv_hex(unsigned int n, t_opts opts, int upper)
{
    char    *s;
    int     len;

    s = ft_itoa_hex(n, upper);
    len = ft_strlen_int(s);
    if (opts.prc > len)
        s = ft_prc_hex(s, len, upper, opts);
    if (opts.wdt > len)
    {
        if (opts.flags.sharp >= 1 && opts.wdt && !opts.flags.dot
            && !opts.flags.zero)
            s = ft_insert_str(s, ft_get_hex(upper), 0);
        s = ft_wdt_hex(s, len, opts);
        if (opts.flags.sharp && opts.flags.zero && !opts.flags.dot)
            s = ft_insert_str(s, ft_get_hex(upper), 0);
    }
    len = ft_strlen_int(s);
    s = ft_opts_hex(s, len, upper, opts);
    if ((s[0] == '0' && s[1] == '\0') && opts.flags.dot && !opts.prc)
        len = 0;
    else
        len = ft_putstr_size(s);
    free(s);
    return (len);
}
