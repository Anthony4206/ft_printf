/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:53:49 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/30 15:45:48 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_flags(t_flags *flags, char c)
{
	if (c == '+')
		flags->plus = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '#')
		flags->sharp = 1;
}