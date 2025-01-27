/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:40:30 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/27 23:22:55 by tbeauman         ###   ########.fr       */
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

void    free_tab(char **tab)
{
    int     i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int    parse(t_env *e, int ac, const char **av)
{
    char    **split;
    char    *join;
    int     i;
    t_list  *new_node;

    join = ft_strjoin_tab((av + 1), ac - 1, " ");
    if (!join)
        return (0);
    split = ft_split(join, ' ');
    if (!split)
        return (free(join), 0);
    i = tab_length(split);
    e->integers = (int*)malloc(sizeof(int) * (i + 1));
    if (!e->integers)
        return (free(join), free_tab(split), 0);
    while (--i >= 0)
    {
        if (!is_int(split[i]))
            return (free(join), free_tab(split), ft_error("Error\n"), 0);
        e->integers[i] = ft_atoi(split[i]);
        new_node = ft_lstnew(e->integers + i);
        if (!new_node)
            return (ft_lstclear(&e->a, &free), free(join), free_tab(split), 0);
        ft_lstadd_front(&e->a, new_node);
        e->size_a++;
    }
    return(free(join), free_tab(split), 1);
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
            ft_error("Errormain.c98\n");
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

void    apply_offset(t_env *e)
{
    int     min;
    t_list  *head;

    head = e->a;
    min = get_min(e->a);
    e->offset = min;
    if (min >= 0)
        return ;
    while(e->a)
    {
        *(unsigned int*)e->a->content -= e->offset;
        e->a = e->a->next;
    }
    e->a = head;
}

void    revert_offset(t_env *e)
{
    t_list  *head;

    head = e->a;
    if (e->offset >= 0)
        return ;
    while (e->a)
    {
        *(int*)e->a->content += e->offset;
        e->a = e->a->next;
    }
    e->a = head;
}

void    apply_plus(t_env *e)
{
    t_list  *head;

    head = e->a;
    while(e->a)
    {
        *(int*)e->a->content += 500;
        e->a = e->a->next;
    }
    e->a = head;
}

void    clean_env(t_env *e)
{
    t_list  *tmp;

    while(e->a)
    {
        tmp = e->a;
        e->a = e->a->next;
        free(tmp);
    }
    free(e->integers);
}

int main(int ac, const char **av)
{
    t_env   e;
    
    if (ac == 1)
        ft_error("");
    init(&e);
    if (!parse(&e, ac, av))
        return (0);
    check_singleton(&e);
    if (is_sorted(e.a))
        return (0);
    // apply_offset(&e);
    // if (!sort(&e))
        // return (0);
    // apply_plus(&e);
    // print_pile_unsigned_bits(e.a);
    if (e.size_a <= 6)
        little_sort(&e);
    else
        radix_sort_opti(&e);
    // print_pile_unsigned_bits(e.a);
    // revert_offset(&e);
    // print_pile(e.a);
    // if (is_sorted(e.a))
    //     ft_printf("lets go");
    clean_env(&e);
    return (0);
}

