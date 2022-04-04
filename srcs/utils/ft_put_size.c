/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:45:04 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/03 12:20:36 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_size(const char *s)
{
	if (!s)
		return (0);
	ft_putstr(s);
	return (ft_strlen(s));
}

int	ft_putchar_size(char c)
{
	ft_putchar(c);
	return (1);
}
