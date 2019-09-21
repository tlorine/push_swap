/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_elem_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:55:41 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:09:34 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_n_l **stack_a, t_n_l **stack_b, t_m_i *com)
{
	if (*stack_b && (*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
	{
		if (com->mas[com->size - 1] == RRA)
			use_command(stack_a, stack_b, RRB, com);
		else if (com->mas[com->size - 1] == RA)
			use_command(stack_a, stack_b, RB, com);
		else if (com->mas[com->size - 1] == SA)
			use_command(stack_a, stack_b, SB, com);
		else
			use_command(stack_a, stack_b, SB, com);
	}
	while (*stack_b != NULL)
		use_command(stack_a, stack_b, PA, com);
}

int		poz_elem_id(int elem, t_n_l *stack)
{
	int i;

	i = 1;
	while (stack && stack->id != elem)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ten_elem_sort(t_n_l **stack_a, t_n_l **stack_b, t_m_i *com)
{
	int	i;
	int	first_elem;

	i = 0;
	sort_id(*stack_a, *stack_b);
	first_elem = poz_elem_id(1, *stack_a);
	while (i != 2 && sorted_stack(*stack_a))
	{
		if ((*stack_a)->id == 1 || (*stack_a)->id == 2)
		{
			if ((*stack_a)->id == 1)
				first_elem = poz_elem_id(2, *stack_a);
			use_command(stack_a, stack_b, PB, com);
			i++;
		}
		else if ((first_elem <= 3 && i == 0) || (first_elem <= 2 && i == 1))
			use_command(stack_a, stack_b, RA, com);
		else
			use_command(stack_a, stack_b, RRA, com);
	}
	sort_five(stack_a, stack_b, com);
	if (*stack_a && (*stack_a)->next && (*stack_a)->id > (*stack_a)->next->id)
		use_command(stack_a, stack_b, SA, com);
}
