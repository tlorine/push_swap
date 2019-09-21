/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred_elem_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:50:28 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:07:49 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	navigation(t_n_l **stack_a, int r, t_m_i *com, char s)
{
	int i;
	int count;

	count = count_list_elem(*stack_a);
	i = r < count / 2 ? 0 : r;
	if (r < count / 2)
	{
		while (i != r)
		{
			com->mas[com->size] = s == 'a' ? RRA : RRB;
			i++;
			reverse_rotate(stack_a);
			com->size = com->size + 1;
		}
	}
	else if (r > count / 2)
	{
		while (i != count)
		{
			com->mas[com->size] = s == 'a' ? RA : RB;
			i++;
			rotate(stack_a);
			com->size = com->size + 1;
		}
	}
}

int		t_split_stack_a(t_n_l **a, t_n_l **b, int count_elem, t_m_i *com)
{
	t_split	sp;
	int		i;

	IN_VAR(i, sp.rev, sp.count);
	sp.middle = search_median_count(*a, count_elem);
	while (count_elem != 0 && *a)
	{
		if (search_first_elem_count(*a, sp.middle, count_elem, 'a') == 1)
			break ;
		if ((*a)->num <= sp.middle)
		{
			use_command(a, b, PB, com);
			(*b)->num == sp.middle ? use_command(a, b, RB, com) : 0;
			PLUS_MIN(sp.count, count_elem);
		}
		else
		{
			use_command(a, b, RA, com);
			PLUS_MIN(sp.rev, count_elem);
		}
	}
	use_command(a, b, RRB, com);
	navigation(a, sp.rev, com, 'a');
	return (sp.count);
}

int		t_split_stack_b(t_n_l **a, t_n_l **b, int count_elem, t_m_i *com)
{
	t_split	sp;
	int		i;

	IN_VAR(i, sp.rev, sp.count);
	sp.middle = search_median_count(*b, count_elem);
	while (count_elem != 0)
	{
		if (search_first_elem_count(*b, sp.middle, count_elem, 'b') == 1)
			break ;
		if ((*b)->num >= sp.middle)
		{
			use_command(a, b, PA, com);
			(*a)->num == sp.middle ? use_command(a, b, RA, com) : 0;
			sp.count++;
		}
		else
		{
			use_command(a, b, RB, com);
			sp.rev++;
		}
		count_elem--;
	}
	navigation(b, sp.rev, com, 'b');
	return (sp.count);
}

void	recursive_five_sort(t_n_l **a, t_n_l **b, int ce, t_m_i *com)
{
	t_split sp;

	IN_VAR(sp.rev, sp.middle, sp.middle);
	if (ce > 3)
	{
		sp.count = t_split_stack_a(a, b, ce, com);
		recursive_five_sort(a, b, ce - sp.count, com);
		if (sp.count > 3)
		{
			sp.rev = t_split_stack_b(a, b, sp.count, com);
			recursive_five_sort(a, b, sp.rev - 1, com);
			use_command(a, b, RRA, com);
		}
		else
			tesb(a, b, sp.count, com);
		sp.middle = sp.rev;
		while (sp.middle < sp.count)
		{
			use_command(a, b, PA, com);
			sp.middle++;
		}
		recursive_five_sort(a, b, sp.count - sp.rev, com);
	}
	else
		tesa(a, b, ce, com);
}

void	five_hundred_elem_sort(t_n_l **a, t_n_l **b, t_m_i *com)
{
	int elements;
	int median;

	elements = count_list_elem(*a);
	recursive_five_sort(a, b, elements, com);
}
