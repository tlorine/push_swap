/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:20:20 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:10:09 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_com_mas(t_m_i *cm, int c, t_n_l **stack_a, t_n_l **stack_b)
{
	cm->mas[cm->size] = c;
	cm->size = cm->size + 1;
}

int		use_command(t_n_l **stack_a, t_n_l **stack_b, int c, t_m_i *com)
{
	if (c == SA)
		swap(stack_a);
	else if (c == SB)
		swap(stack_b);
	else if (c == PA)
		push(stack_b, stack_a);
	else if (c == PB)
		push(stack_a, stack_b);
	else if (c == RA)
		rotate(stack_a);
	else if (c == RB)
		rotate(stack_b);
	else if (c == RRA)
		reverse_rotate(stack_a);
	else if (c == RRB)
		reverse_rotate(stack_b);
	fill_com_mas(com, c, stack_a, stack_b);
	return (1);
}
