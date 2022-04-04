/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 06:59:46 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/03 12:06:54 by Anthony          ###   ########.fr       */
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

int		ft_printf(const char *fmt, ...);
int		ft_parser(const char *fmt, va_list args);
int 	ft_define_args(const char *fmt, va_list args, int *i);
t_opts	ft_get_opts(const char *fmt, int *i);
int		ft_is_flag(char c);
void	ft_add_flags(t_flags *flags, char c);

int 	ft_conv_char(int c, t_opts opts);
int 	ft_conv_str(char *s, t_opts opts);
int		ft_conv_int(int n, t_opts opts);
int 	ft_conv_uint(unsigned int n, t_opts opts);
int 	ft_conv_hex(unsigned int n, t_opts opts, int upper);
int 	ft_conv_ptr(unsigned long n, t_opts opts);

int		ft_putchar_size(char c);
int		ft_putstr_size(const char *s);
int		ft_strlen_int(const char *s);
char	*ft_insert_str(char *s, char *ins, int pos);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_hex(unsigned int n, int upper);
char	*ft_itoa_ptr(unsigned long n);

#endif 
