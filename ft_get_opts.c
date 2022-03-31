/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:31:32 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/30 19:06:02 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_get_flags(const char *fmt, int *i)
{
	t_flags	flags;

	flags.plus = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.space = 0;
	flags.sharp = 0;
	flags.dot = 0;
	while (ft_is_flag(fmt[*i]))
	{
		ft_add_flag(flags, fmt[*i])
		(*i)++;
	}
	return (flags);
}

static int	ft_get_wdt(const char *fmt, int *i)
{
	int	wdt;

	wdt = 0;
	if (ft_isdigit(fmt[*i]))
	{
		wdt = ft_atoi(fmt[i]);
		while (ft_isdigit(fmt[*i]))
			(*i)++;
	}
	return (wdt);
}

static int	ft_get_prc(const char *fmt, int *i)
{
	int	prc;

	if (*fmt[*i] != '.')
		return (NULL);
	if (*fmt[*i] == '.')
	{
		prc = 0;
		*i++;
		if (ft_isdigit(*fmt[*i]))
		{
			prc = ft_atoi(fmt[*i]);
			while (*fmt[*i])
				*i++;
		}
	}
	return (prc);
}

t_opts	ft_get_opts(const char *fmt, int *i)
{
	t_opts	opts;

	opts.flags = ft_get_flags(fmt, i);
	opts.wdt = ft_get_wdt(fmt, i);
	if (fmt[*i] == '.')
		opts.flags.dot = 1;
	opts.prc = ft_get_prc(fmt, i);
	return (opts);
}