/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:14 by achakour          #+#    #+#             */
/*   Updated: 2024/03/26 13:58:02 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char *flag)// too many functions
{
	int	i;

	i = 0;
	while (flag[i])
	{
		write(1, &flag[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

void	rra_rrb_rrr(t_push **stack, char *flag)
{
	t_push	*head;
	t_push	*tmp;

	head = *stack;
	while (head->next->next)
	{
		head = head->next;
	}
	tmp = head;
	head->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	if (flag[2] != 'p')
	{
		ft_putchar(flag);
	}
}

void	ra_rb_rr(t_push **stack, char *flag)
{
	t_push	*head;
	t_push	*tmp;

	head = *stack;
	tmp = head->next;
	while (head->next)
	{
		head = head->next;
	}
	head->next = *stack;
	*stack = tmp;
	head->next->next = NULL;
	if (flag[2] != 'p')
	{
		ft_putchar(flag);
	}
}

void	rr_rrr(t_push **stack_a, t_push **stack_b, char *flag)
{
	if (flag[0] == 'r' && flag[1] == 'r' && !flag[2])
	{
		ra_rb_rr(stack_a, "rr");
		ra_rb_rr(stack_b, "nop");
	}
	else if (flag[0] == 'r' && flag[1] == 'r' && flag[2] == 'r')
	{
		rra_rrb_rrr(stack_a, "rrr");
		rra_rrb_rrr(stack_b, "nop");
	}
}

int	push_node(t_push **stack_a, t_push **stack_b, int a_len, char *flag)
{
	t_push	*head;
	int		b_len;
	int		tmp;

	b_len = ft_lstsize(*stack_b);
	if (flag[1] == 'b' && a_len == 1)
	{
		head = *stack_a;
		tmp = head->data;
		ft_lstadd_front(stack_b, ft_lstnew(tmp));
		ft_lstdelone(&head);
		ft_putchar(flag);
		return (1);
	}
	else if (flag[1] == 'a' && b_len == 1)
	{
		head = *stack_b;
		tmp = head->data;
		ft_lstadd_front(stack_a, ft_lstnew(tmp));
		ft_lstdelone(&head);
		ft_putchar(flag);
		return (1);
	}
	return (0);
}

void	pa_pb(t_push **stack_a, t_push **stack_b, char *flag)
{
	int		tmp;
	t_push	*head;

	if (push_node(stack_a, stack_b, ft_lstsize(*stack_a), flag))
	{
		return ;
	}
	if (flag[1] == 'b')
	{
		head = *stack_a;
		tmp = head->data;
		*stack_a = head->next;
		ft_lstadd_front(stack_b, ft_lstnew(tmp));
		ft_lstdelone(&head);
	}
	else if (flag[1] == 'a')
	{
		head = *stack_b;
		tmp = head->data;
		*stack_b = head->next;
		ft_lstadd_front(stack_a, ft_lstnew(tmp));
		ft_lstdelone(&head);
	}
	ft_putchar(flag);
}

void	sa_sb(t_push **stack, char *flag)
{
	int		tmp;
	t_push	*head;

	if (!stack)
	{
		return ;
	}
	head = *stack;
	if (!head->next)
	{
		return ;
	}
	tmp = head->data;
	head->data = head->next->data;
	head->next->data = tmp;
	ft_putchar(flag);
}
