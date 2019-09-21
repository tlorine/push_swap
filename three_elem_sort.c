/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:13:31 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:09:52 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elem_sort(t_n_l **stack_a, t_n_l **stack_b, t_m_i *com)
{
	int max_elem;
	int i;

	max_elem = search_max_elem(*stack_a);
	if (sorted_stack(*stack_a) == 0)
		return ;
	i = search_elem_poz(*stack_a, max_elem) + 1;
	if (i == 3 && (*stack_a)->num > (*stack_a)->next->num)
		use_command(stack_a, stack_a, SA, com);
	else if (i == 1)
	{
		use_command(stack_a, stack_a, RA, com);
		if ((*stack_a)->next->next && (*stack_a)->num > (*stack_a)->next->num)
			use_command(stack_a, stack_a, SA, com);
	}
	else if (i == 2 && (*stack_a)->next->next)
	{
		use_command(stack_a, stack_a, RRA, com);
		if ((*stack_a)->next->next && (*stack_a)->num > (*stack_a)->next->num)
			use_command(stack_a, stack_a, SA, com);
	}
	return ;
}

void	tesa(t_n_l **stack_a, t_n_l **stack_b, int count, t_m_i *com)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		use_command(stack_a, stack_b, SA, com);
	if (count == 3 && (*stack_a)->next->num > (*stack_a)->next->next->num)
	{
		use_command(stack_a, stack_b, PB, com);
		use_command(stack_a, stack_b, SA, com);
		use_command(stack_a, stack_b, PA, com);
	}
	if ((*stack_a)->num > (*stack_a)->next->num)
		use_command(stack_a, stack_b, SA, com);
}

void	tesb(t_n_l **stack_a, t_n_l **stack_b, int count, t_m_i *com)
{
	if ((*stack_b)->num < (*stack_b)->next->num)
		use_command(stack_a, stack_b, SB, com);
	if (count == 3 && (*stack_b)->next->num < (*stack_b)->next->next->num)
	{
		use_command(stack_a, stack_b, PA, com);
		use_command(stack_a, stack_b, SB, com);
		use_command(stack_a, stack_b, PB, com);
	}
	if ((*stack_b)->num < (*stack_b)->next->num)
		use_command(stack_a, stack_b, SB, com);
}
