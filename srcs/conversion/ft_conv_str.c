#include "ft_printf.h"

static char *ft_wdt_str(char *s, t_opts opts)
{
	int		len;
    int		new_len;
	char	*new;
	
	len = ft_strlen(s);
	new_len = 0;
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
	free (s);
	return (new);
}

static char	*prc_str(char *s, t_opts opts)
{
	char	new;

	new = ft_substr(s, 0, opts.prc);
	free (s);
	return (new);
}

int ft_conv_str(char *s, t_opts opts)
{
    int     len;
    char    *new;

    if (!s)
        s = "(null)";
    new = ft_strdup(s);	
	len = ft_strlen(new);
    if (opts.prc <= len && opts.prc)
        new = ft_prc_str(new, opts);
    if (opts.wdt > len)
        new = ft_wdt_str(new, opts);
    ft_putstr(new);
    len = ft_strlen(new);
    free (new);
	return (len);
}
