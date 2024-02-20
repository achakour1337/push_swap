/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:07:56 by achakour          #+#    #+#             */
/*   Updated: 2024/02/20 15:26:34 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

 #include <limits.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>

typedef struct inst
{
    int *pos;
    char *ins;
    int index;
    struct inst *next;
} inst;

typedef struct push
{
    int            data;
    struct  push  *next;
}           push;

void    rra_rrb_rrr(push **stack, push **last,char *flag);
void    ra_rb_rr(push **stack, char *flag);
void    sa_sb_ss(push *stack, char *flag);
void    pa_pb(push **a, push **b, char *flag);
int     is_lis(int *arr, int len,int n);

int     ft_double_numbers(int *arr, int n, unsigned int len);
void    rotate_half_stack(push **stack, int len, char *flag);
size_t     *lst_weight(push *stack, int len);
int *find_cheapest(push *stack, int len);
int ft_min(int *arr, int len);
int     ft_is_all_digit(int ac, char **ar);
int     ft_check_dobles_limits(int ac, char **ar);
push    *get_args(int ac, char **ar);
void	ft_lstclear(push **lst);
int ft_max(push *stack);
// int *count_push_price(push *stack, int n);
void    move_up_down_push(push **stack_a, push **stack_b, int n, char flag);

void	ft_lstadd_back(push **lst, push *new);
int	    ft_lstsize(push *lst);
push	*ft_lstnew(int content);
int    *ft_lis(push *lst, int *len);
// ah torta9 lbarod
char	**ft_split(char const *s, char c);
void    filter_lst(push **stack_a, push **stack_b);
push    *find_last_node(push *stack);
int    *ft_fill_arr(push *lst);

#endif
