/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:38 by achakour          #+#    #+#             */
/*   Updated: 2024/03/13 10:32:32 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(push **lst, push *new)
{
	if (!new || lst == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *(lst);
	*lst = new;
}

void	ft_lstadd_back(push **lst, push *new)
{
	push	*head;

	if (!new || lst == NULL)
	{
		return ;
	}
	head = *lst;
	if (!head)
	{
		*lst = new;
		return ;
	}
	while (head->next)
	{
		head = head->next;
	}
	head->next = new;
}

void	ft_lstclear(push **lst)
{
	push	*next_node;

	if (lst == NULL || *lst == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		next_node = (*lst)->next;
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}

void	ft_lstdelone(push **lst)
{
	if (lst == NULL)
	{
		return ;
	}
	free (*lst);
	lst = NULL;
}

int	ft_lstsize(push *lst)
{
	push	*head;
	int		len;

	len = 0;
	if (!lst)
	{
		return (0);
	}
	head = lst;
	while (head != NULL)
	{
		head = head->next;
		++len;
	}
	return (len);
}

push	*ft_lstnew(int content)
{
	push	*node;

	node = (push *)malloc(sizeof(push));
	if (!node)
	{
		return (NULL);
	}
	node->data = content;
	node->next = NULL;
	return (node);
}

push    *find_last_node(push *stack)
{
	if (!stack)
	{
		return (NULL);
	}
    while (stack->next)
	{
        stack = stack->next;
	}
    return(stack);
}