/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:40:30 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/26 21:26:59 by tbeauman         ###   ########.fr       */
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

int    parse(t_env *e, int ac, const char **av)
{
    char    **split;
    char    *join;
    int     i;
    int     *integers;
    t_list  *new_node;

    join = ft_strjoin_tab((av + 1), ac - 1, " ");
    if (!join)
        return (0);
    split = ft_split(join, ' ');
    if (!split)
        return (free(join), 0);
    i = tab_length(split);
    integers = (int*)malloc(sizeof(int) * (i + 1));
    if (!integers)
        return (free(join), free(split), 0);
    while (--i >= 0)
    {
        integers[i] = ft_atoi(split[i]);
        new_node = ft_lstnew(integers + i);
        if (!new_node)
            return (ft_lstclear(&e->a, &free), free(join), free(split), 0);
        ft_lstadd_front(&e->a, new_node);
        e->size_a++;
    }
    return(free(join), free(split), 1);
}

int     is_int(const char *str)
{
    int     i;
    long    n;

    i = 0;
    while (str[i])
    {
        if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
            return(0);
        i++;
    }
    if (ft_strlen(str) == 0 || ft_strlen(str) > 11)
        return (0);
    if (ft_strlen(str) >= 10)
    {
        n = ft_atol(str);
		if (n > 2147483647 || n < -2147483648)
			return (0);
    }
    return (1);
}

void    check_args(int ac, const char **av)
{
    int     i;

    i = 1;
    while (i < ac)
    {
        if (!is_int(av[i]))
            ft_error("Error\n");
        i++;
    }
}

void    init(t_env *e)
{
    e->a = 0;
    e->b = 0;
    e->size_a = 0;
    e->size_b = 0;
}

void    check_singleton(t_env *e)
{
    int     cmp;
    t_list  *head1;
    t_list  *head2;

    head1 = e->a;
    while (head1->next)
    {
        cmp = *(int*)head1->content;
        head2 = head1->next;
        while (head2)
        {
            if (cmp == *(int*)head2->content)
                ft_error("Singletons error\n");
            head2 = head2->next;
        }
        head1 = head1->next;
    }
}

int main(int ac, const char **av)
{
    t_env   e;
    
    if (ac == 1)
        ft_error("");
    check_args(ac, av);
    init(&e);
    if (!parse(&e, ac, av))
        return (0);
    check_singleton(&e);
    if (!sort(&e))
        return (0);
    // print_pile(e.a);
    return (0);
}