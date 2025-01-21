/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:16:11 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/21 21:27:19 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin_tab(const char **tab, int size, const char *sep)
{
    int     i;
    char    *ret;
    char    *tmp;

    i = 0;
    ret = 0;
    while (i < size)
    {
        tmp = ft_strjoin(ret, sep);
        if (!tmp)
            return (NULL);
        ret = ft_strjoin(tmp, tab[i]);
        // free(tmp);
        // tmp = NULL;
        if (!ret)
            return (NULL);
        i++;
    }
    return (ret);
}