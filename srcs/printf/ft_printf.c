/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 06:59:49 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/03 14:31:23 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(const char *fmt, va_list args)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			len += ft_define_args(fmt, args, &i);
		}
		else
			len += ft_putchar_size(fmt[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		ret;

	va_start(args, fmt);
	ret = ft_parser(fmt, args);
	va_end(args);
	return (ret);
}
