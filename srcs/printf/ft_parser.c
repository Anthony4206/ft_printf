/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:02:05 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/01 14:18:35 by alevasse         ###   ########.fr       */
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
		}
			len += ft_putchar_size(fmt[i]);
			i++;
		}
	}
	return (len);
}