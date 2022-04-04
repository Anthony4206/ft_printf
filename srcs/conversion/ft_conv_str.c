#include "ft_printf.h"

static char *ft_wdt_str(char *s, int len, t_opts opts)
{
	int		wd_len;
    int		new_len;
	char	*new;
	
	new_len = 0;
	wd_len = opts.wdt;
	new = ft_strdup(s);
	ft_putnbr(opts.wdt);
	ft_memset(new, ' ', wd_len);
	new[opts.wdt] = '\0';
	if (opts.flags.minus >= 1)
	{
		ft_putendl("cpy is ok");
		ft_strncpy(new, s, len);
	}
	else
	{
		new_len = wd_len - len;
		ft_strncpy(&new[new_len], s, len);
	}
	free (s);
	return (new);
}

static char	*ft_prc_str(char *s, t_opts opts)
{
	char	*new;

	new = ft_substr(s, 0, opts.prc);
	free (s);
	return (new);
}

int ft_conv_str(char *s, t_opts opts)
{
    char    *new;
	int     len;

    if (!s)
        s = "(null)";
    new = ft_strdup(s);	
	len = ft_strlen_int(new);
    if (opts.prc <= len && opts.prc)
        new = ft_prc_str(new, opts);
    if (opts.wdt > len)
        new = ft_wdt_str(new, len, opts);
	ft_putstr(new);
    len = ft_strlen_int(new);
    free (new);
	return (len);
}
