#include "ft_printf.h"

int ft_strlen_int(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
