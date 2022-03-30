/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 06:59:49 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/30 15:46:04 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		ret;


	va_start(args, fmt);
	i = 0;
	ret = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			ret += ft_define_args(fmt, args, i);
		}
		else
			ret += ft_putchar_add(fmt[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
