/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:38:46 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:08:25 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_push_a(t_n_l **a, t_n_l **b, t_m_i *c)
{
	t_r_v r;

	if (*b == NULL || count_list_elem(*b) < 1)
		return ;
	r.min_elem = search_min_elem(*b);
	r.m_e = count_list_elem(*b) / 2;
	r.max_elem = search_max_elem(*b);
	r.next_max_elem = search_next_max_elem(*b, r.max_elem);
	r.p_e = search_elem_poz(*b, r.max_elem);
	while ((*b)->num != r.max_elem)
	{
		if ((*b)->num == r.next_max_elem)
			use_command(a, b, PA, c);
		else if ((*b)->num == r.min_elem)
		{
			use_command(a, b, PA, c);
			use_command(a, b, RA, c);
		}
		else
			r.p_e >= r.m_e ? use_command(a, b, 10, c) : use_command(a, b, 7, c);
	}
	use_command(a, b, PA, c);
	(*a)->num > (*a)->next->num ? use_command(a, b, SA, c) : 0;
	recursive_push_a(a, b, c);
}

int		t_split_stack(t_n_l **a, t_n_l **b, int middle, t_m_i *c)
{
	int count;
	int count_elem;
	int first_elem;
	int i;

	count_elem = count_list_elem(*a);
	i = 0;
	count = 0;
	while (i < count_elem && sorted_stack(*a) && *a)
	{
		if (search_first_elem(*a, middle) == 1)
			return (count);
		first_elem = search_first_elem_poz(*a, middle);
		if ((*a)->num <= middle)
		{
			use_command(a, b, PB, c);
			count++;
		}
		else if (first_elem < count_elem / 2)
			use_command(a, b, RA, c);
		else
			use_command(a, b, RRA, c);
		i++;
	}
	return (count);
}

void	recursive_sort(t_n_l **a, t_n_l **b, t_m_i *c)
{
	int median;
	int min;
	int count;

	if (count_list_elem(*a) > 3 && *a != NULL && sorted_stack(*a))
	{
		median = search_median(*a);
		t_split_stack(a, b, median, c);
		recursive_sort(a, b, c);
	}
	else
		three_elem_sort(a, b, c);
}

void	hundred_elem_sort(t_n_l **a, t_n_l **b, t_m_i *c)
{
	recursive_sort(a, b, c);
	recursive_push_a(a, b, c);
	while ((*a)->num != search_min_elem(*a))
		use_command(a, b, RRA, c);
}
