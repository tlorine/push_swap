/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_elem_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:48:56 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:10:29 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_max_elem(t_n_l *stack)
{
	int elem;

	elem = 0;
	if (stack)
		elem = stack->num;
	while (stack)
	{
		if (elem < stack->num)
		{
			elem = stack->num;
		}
		stack = stack->next;
	}
	return (elem);
}

int	search_elem_poz(t_n_l *stack, int elem)
{
	int i;

	i = 0;
	while (stack && stack->num != elem)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	search_first_elem_poz(t_n_l *stack, int middle)
{
	int i;

	i = 0;
	while (stack && stack->num > middle)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	search_first_elem(t_n_l *stack, int middle)
{
	while (stack != NULL)
	{
		if (stack->num <= middle)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	search_first_elem_count(t_n_l *stack, int middle, int max, char s)
{
	int i;

	i = 0;
	if (s == 'b')
	{
		while (stack != NULL && i < max)
		{
			if (stack->num >= middle)
				return (0);
			stack = stack->next;
			i++;
		}
		return (1);
	}
	while (stack != NULL && i < max)
	{
		if (stack->num <= middle)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}
