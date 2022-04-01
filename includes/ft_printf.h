/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 06:59:46 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/31 09:12:31 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int		plus;	
	int		minus;	
	int		zero;	
	int 	space;	
	int		sharp;
	int		dot;
}			t_flags;

typedef struct	s_opts
{
	t_flags	flags;
	int		wdt;
	int		prc;
}			t_opts;

int	ft_printf(const char *fmt, ...);
int	ft_parser(const char *fmt, va_list args);
int	ft_putchar_add(char c);
int 	ft_define_args(const char *fmt, va_list args, int *i);
t_opts	ft_get_opts(const char *fmt, int *i);
void	ft_add_flags(t_flags *flags, char c);

#endif 
