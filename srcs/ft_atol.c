/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:31:12 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 17:06:43 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	ret;
	int		sgn;
	int		i;

	i = 0;
	ret = 0;
	sgn = 1;
	while (*str == '\t' || *str == '\f' || *str == '\v' || *str == '\r' ||
			*str == '\n' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
        if (*str == '-')
            sgn = -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		ret = 10 * ret + (str[i] - '0');
		i++;
	}
	return (sgn * ret);
}
