/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 06:59:49 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/01 13:18:36 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		ret;

	
	va_start(args, fmt);
	ret = ft_parser(fmt, args);
	va_end(args);
	return (ret);
}
