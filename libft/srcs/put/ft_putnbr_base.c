#include "ft_printf.h"

void    ft_putnbr_base(unsigned int n, char *base)
{
    if (n >= ft_strlen(base))
        ft_putnbr_base(n / ft_strlen(base), base);
    ft_putchar(base[n % ft_strlen(base)]);
}