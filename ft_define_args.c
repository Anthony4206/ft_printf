/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:50:31 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/30 15:45:47 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_define_args(const char **fmt, va_list args, int *i)
{
	t_opts	opts;

	opts = ft_get_opts(fmt, *i);
	if (fmt[*i] == 'c')
		return (ft_conv_char(va_arg(args, int), opts));
	else if (fmt[*i] == 's')
		return (ft_conv_str(va_arg(args, char *), opts));
	else if (fmt[*i] == 'd' || fmt == 'i')
		return (ft_conv_int(va_arg(args, int), opts));
	else if (fmt[*i] == 'u')
		return (ft_conv_uint(va_arg(args, unsigned int), opts));
	else if (fmt[*i] == 'x')
		return (ft_conv_hex(va_arg(args, unsigned int), opts));
	else if (fmt[*i] == 'X')
		return (ft_conv_upper_hex(va_arg(args, unsigned int), opts));
	else if (fmt[*i] == 'p')
		return (ft_conv_ptr(va_arg(args, unsigned long), opts));
	else
		return (ft_conv_char(c, opts));
}