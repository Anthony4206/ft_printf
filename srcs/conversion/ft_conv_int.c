#include "ft_printf.h"

static char	*ft_wdt_int(char *s, int len, t_opts opts)
{
	char	*new;
	int		new_len;

	new = ft_strdup(s);
	ft_memset(new, ' ', opts.wdt);
	new[opts.wdt] = '\0';
	if (opts.flags.zero && !opts.flags.minus && !opts.prc)
	{
		ft_memset(new, '0', opts.wdt);
		if (opts.flags.plus)
			new[0] = '+';
	}
	if (opts.flags.minus)
		ft_strncpy(new, s, len);
	else
	{
		new_len = opts.wdt - len;
		ft_strncpy(&new[new_len], s, len);
	}
	free (s);
	return (new);
}

static char	*ft_neg_prc(char *s, int len, t_opts opts)
{
	char	*new;

	new = ft_strdup(s);
	new[0] = '0';
	if (!opts.flags.zero && opts.wdt && !opts.prc)
	{
		new[0] = '-';
		new = ft_wdt_int(new, len, opts);
	}
	else
	{
		len = ft_strlen_int(new);
		new = ft_wdt_int(new, len, opts);
		new[0] = '-';
	}
	free(s);
	return (new);
}

static char	*ft_prc_int(char *s, int len, int neg, t_opts opts)
{
	char	*new;
	int		new_len;

	new = ft_strdup(s);
	new[opts.prc] = '\0';
	if (neg)
		s[0] = '0';
	if (opts.prc >= len)
	{
		ft_memset(new, '0', opts.prc);
		new_len = opts.prc - len;
		ft_strncpy(&new[new_len], s, len);
	}
	if (neg)
		new = ft_insert_str(new, "-", 0);
	if (opts.flags.plus && !neg)
		new = ft_insert_str(new, "+", 0);
	free(s);
	return (new);
}

static char	*ft_opts_int(char *s, int len, int neg, t_opts opts)
{
	char	*new;

	new = ft_strdup(s);
	if (opts.flags.plus && !opts.flags.zero && !opts.prc && !neg)
		ft_insert_str(new, "+", 0);
	if (opts.prc >= ft_strlen_int(new))
	{
		len = ft_strlen_int(new);
		new = ft_prc_int(new, len, neg, opts);
	}
	if (opts.wdt > ft_strlen_int(new))
	{
		len = ft_strlen_int(new);
		new = ft_wdt_int(new, len, opts);
	}
	if (opts.flags.space && !opts.flags.plus && !opts.prc && !neg)
		new = ft_insert_str(new, " ", 0);
	free(s);
	return (new);
}

int	ft_conv_int(int n, t_opts opts)
{
	char	*s;
	int		neg;
	int		len;

	neg = 0;
	if (n < 0)
		neg = 1;
	s = ft_itoa(n);
	len = ft_strlen_int(s);
	if (neg && opts.wdt > len)
		s = ft_neg_prc(s, len, opts);
	s = ft_opts_int(s, len, neg, opts);
	len = ft_strlen_int(s);
	if (s[len - 1] == '0' && opts.flags.dot 
		&& !opts.prc && opts.wdt && !opts.flags.zero)
		ft_memset(s, ' ', len);
	if (s[len - 1] == '0' && opts.flags.dot && !opts.prc && !opts.flags.zero)
		len = 0;
	else
		len = ft_putstr_size(s);
	free(s);
	return (len);
}
