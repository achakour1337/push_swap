/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:07:56 by achakour          #+#    #+#             */
/*   Updated: 2024/03/04 13:00:24 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

 #include <limits.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>

typedef struct push
{
    int            data;
    struct  push  *next;
}           push;

void    rra_rrb_rrr(push **stack, char *flag);
void    ra_rb_rr(push **stack, char *flag);
void    rr_rrr(push **stack_a, push **stack_b, char *flag);
void    sa_sb_ss(push *stack, char *flag);
void    pa_pb(push **a, push **b, char *flag);
int     is_lis(int *arr, int len,int n);

void	ft_lstdelone(push **lst);
int     *ft_fill_arr(push *lst);
void	ft_lstadd_front(push **lst, push *new);
void   stack_recovery(push **stack_a, push **stack_b);
int select_cheapest(push *stack_a, push *stack_b, int b_len, int a_len);
void    fix_lst(push **stack, int len);
int     *count_push_price(push *stack_a, push *stack_b, int n, int target, int b_len);
int detect_target(int *arr, int n,int a_len);
void find_cheapest_in_a(push *stack, int **cheap, int target, int a_len);
void    rotate_half_stack(push **stack, int len, char *flag);
size_t  *lst_weight(push *stack, int len);
int     ft_double_numbers(int *arr, int n, unsigned int len);
int     ft_is_all_digit(int ac, char **ar);
int     ft_check_dobles_limits(int ac, char **ar);
push    *get_args(int ac, char **ar);
void	ft_lstclear(push **lst);
int     ft_max(push *stack);
// int *count_push_price(push *stack, int n);

void	ft_lstadd_back(push **lst, push *new);
int	    ft_lstsize(push *lst);
push	*ft_lstnew(int content);
int    *ft_lis(push *lst, int *len);
// ah torta9 lbarod
char	**ft_split(char const *s, char c);
push    *find_last_node(push *stack);
int     *ft_fill_arr(push *lst);

#endif
