/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:50:43 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:06:17 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_n_l **list)
{
	if (*list && (*list)->next)
	{
		(*list)->back = (*list)->next;
		(*list)->next = (*list)->next->next;
		(*list)->back->next = (*list);
		(*list)->back->back = NULL;
		(*list) = (*list)->back;
	}
}

void	push(t_n_l **st_one, t_n_l **st_two)
{
	if (*st_two == NULL && *st_one)
	{
		*st_two = *st_one;
		*st_one = (*st_one)->next;
		(*st_one)->back = NULL;
		(*st_two)->next = NULL;
	}
	else if (*st_one)
	{
		(*st_two)->back = *st_one;
		*st_one = (*st_one)->next;
		if (*st_one)
			(*st_one)->back = NULL;
		(*st_two)->back->next = (*st_two);
		(*st_two)->back->back = NULL;
		*st_two = (*st_two)->back;
	}
}

void	rotate(t_n_l **stack)
{
	t_n_l *begin;

	begin = *stack;
	if (begin && begin->next != NULL)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = *stack;
		(*stack)->back = begin;
		(*stack) = (*stack)->next;
		(*stack)->back->next = NULL;
		(*stack)->back = NULL;
	}
}

void	reverse_rotate(t_n_l **stack)
{
	t_n_l *begin;

	begin = *stack;
	if (begin && begin->next != NULL)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->back->next = NULL;
		begin->back = NULL;
		begin->next = *stack;
		(*stack)->back = begin;
		*stack = begin;
	}
}
