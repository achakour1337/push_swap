/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:14 by achakour          #+#    #+#             */
/*   Updated: 2024/02/21 09:39:44 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra_rrb_rrr(push **stack, push **last, char *flag)
{
    push    *head;
    push    *tmp;

    head = *stack;
    while (head->next->next)
        head = head->next; 
   tmp = head;
   if (last && *last)
    *last = tmp;
   head->next->next = *stack;
   *stack = tmp->next;
   tmp->next = NULL;
   if (flag[2] != 'p')
    printf ("%s\n", flag);
}

void    ra_rb_rr(push **stack, char *flag)
{
    push    *head;
    push    *tmp;

    head = *stack;
    tmp = head->next;
    while (head->next)
        head = head->next;
    head->next = *stack;
    *stack = tmp;
    head->next->next = NULL;
    if (flag[2] != 'p')
        printf("%s\n", flag);
}

void rr_rrr(push **stack_a, push **stack_b, char *flag)
{
    push    *last;
    if (flag[0] == 'r' && !flag[2])
    {
        ra_rb_rr(stack_a, "nop");
        ra_rb_rr(stack_b, "rr");
    }
    else
    {
        rra_rrb_rrr(stack_a, &last, "nop");
        rra_rrb_rrr(stack_b, &last, "rrr");
    }
}

void    sa_sb_ss(push *stack, char *flag)
{
    int tmp;

    if (!stack->next)
        return ;
    while (stack->next->next)
        stack = stack->next;
    if (!stack->next)
        return ;
    tmp = stack->next->data;
    stack->next->data = stack->data;
    stack->data = tmp;
    printf ("%s \n", flag);
}

int    push_node(push **stack_a, push **stack_b, int a_len, int b_len,char *flag)
{
    push    *head;
    int     tmp;

    if (flag[1] == 'a' && a_len == 1)
    {
        head = *stack_a;
        tmp = head->data;
        ft_lstadd_back(stack_b, ft_lstnew(tmp));
        ft_lstclear(stack_a);
        return (1);
    }
    else if (flag[1] == 'b' && b_len == 1)
    {
        head = *stack_b;
        tmp = head->data;
        ft_lstadd_back(stack_a, ft_lstnew(tmp));
        ft_lstclear(stack_b);
        return (1);
    }
    return (0);
}

void    pa_pb(push **stack_a, push **stack_b ,char *flag)
{
    int     tmp;
    push    *head;

    if (push_node(stack_a, stack_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b),flag))
        return ;
    if (flag[1] == 'a')
    {
        head = *stack_a;
        while (head->next->next)
            head = head->next;
        tmp = head->next->data;
        ft_lstadd_back(stack_b, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    else if (flag[1] == 'b')
    {
        head = *stack_b;
        while (head->next->next)
            head = head->next;
        tmp = head->next->data;
        ft_lstadd_back(stack_a, ft_lstnew(tmp));
        ft_lstclear(&head->next);
    }
    printf ("%s \n", flag);
}
