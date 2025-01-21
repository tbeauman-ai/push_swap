/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:40:30 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/21 21:34:55 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int tab_length(char **tab)
{
    int     i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

int main(int ac, const char **av)
{
    t_env   *e;
    char    **split;
    char    *join;
    int     i;
    int     *integers;
    
    if (ac == 1)
        ft_error("");
    join = ft_strjoin_tab((av + 1), ac - 1, " ");
    split = ft_split(join, ' ');
    free(join);
    i = 0;
    e = (t_env*)malloc(sizeof(t_env));
    while (split[i])
    {
        // integers[i] = ft_atoi(split[i]);
        // (void)n;
        // char *s = split[i];
        // ft_lstadd_back(&e->a, ft_lstnew(integers + i));
        // ft_lstadd_back(&e->a, ft_lstnew(s));
        i++;
    }
    integers = (int*)malloc(sizeof(int) * (i + 1));
    while (--i >= 0)
    {
        integers[i] = ft_atoi(split[i]);
        ft_lstadd_front(&e->a, ft_lstnew(integers + i));
    }
    while (e->a)
    {
        // ft_printf("%s/", (char*)e->a->content);
        ft_printf("%d/", *(int*)e->a->content);
        e->a = e->a->next;
    }
    return (0);
}