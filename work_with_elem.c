/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:59:51 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:13:01 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_n_l **stack)
{
	t_n_l *stack_buffer;

	while (*stack)
	{
		stack_buffer = *stack;
		free(stack_buffer);
		stack_buffer = NULL;
		*stack = (*stack)->next;
	}
}

int		search_median(t_n_l *buffer)
{
	t_m_i	*mas;
	int		median;
	int		i;

	i = 0;
	mas = create_mas(buffer);
	sort_mas(mas->mas, mas->size);
	median = mas->mas[(mas->size / 2) - 1];
	free(mas->mas);
	mas->mas = NULL;
	free(mas);
	mas = NULL;
	return (median);
}

int		search_median_count(t_n_l *stack_a, int count)
{
	t_n_l	*buffer;
	t_n_l	*tmp;
	t_n_l	*start_buffer;
	int		i;

	i = 0;
	tmp = stack_a;
	while (i < count && tmp)
	{
		if (i == 0)
		{
			buffer = (t_n_l *)malloc(sizeof(t_n_l));
			start_buffer = buffer;
		}
		else
		{
			buffer->next = (t_n_l *)malloc(sizeof(t_n_l));
			buffer = buffer->next;
		}
		STEP_MED(buffer, tmp, i);
	}
	buffer->next = NULL;
	i = search_median(start_buffer);
	free_list(&start_buffer);
	return (i);
}

int		search_min_elem(t_n_l *stack)
{
	int elem;

	if (stack)
		elem = stack->num;
	while (stack)
	{
		if (elem > stack->num)
			elem = stack->num;
		stack = stack->next;
	}
	return (elem);
}

int		search_next_max_elem(t_n_l *stack, int max)
{
	int elem;

	elem = 0;
	while (stack)
	{
		if (elem < stack->num && stack->num != max)
			elem = stack->num;
		stack = stack->next;
	}
	return (elem);
}
