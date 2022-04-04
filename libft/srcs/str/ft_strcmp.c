/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:17:37 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/31 08:17:38 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}