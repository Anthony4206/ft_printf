#include "ft_printf.h"

static char *ft_prc_uint(char *s, int len, t_opts opts)
{
    char    *new;
    int     new_len;

    new = ft_strnew(opts.prc);
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

    new = ft_strnew(opts.wdt);
    ft_memset(new, ' ', opts.wdt);
	ft_putendl(new);
	ft_putnbr(ft_strlen_int(new));
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
	ft_putendl("lol");
	ft_putendl(s);
	ft_putendl("lol");
    len = ft_strlen_int(s);
	ft_putnbr(len);
	ft_putchar('\n');
	if (!opts.prc && opts.flags.dot && n == 0)
		s[0] = '\0';
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