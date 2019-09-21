/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:55:56 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:15:31 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				search_max_elem_id(t_n_l *stack)
{
	int			elem;

	elem = 0;
	while (stack->id != -1)
		stack = stack->next;
	if (stack)
		elem = stack->num;
	while (stack)
	{
		if (elem < stack->num && stack->id == -1)
		{
			elem = stack->num;
		}
		stack = stack->next;
	}
	return (elem);
}

void			sort_id(t_n_l *stack_a, t_n_l *stack_b)
{
	t_n_l		*point_newa;
	int			count;
	int			max;

	point_newa = stack_a;
	count = count_list_elem(stack_a);
	while (stack_a != NULL)
	{
		stack_a->id = -1;
		stack_a = stack_a->next;
	}
	while (count != 0)
	{
		stack_a = point_newa;
		max = search_max_elem_id(stack_a);
		while (stack_a->num != max && stack_a)
			stack_a = stack_a->next;
		stack_a->id = count;
		count--;
	}
}

t_n_l			*create_elem(int content)
{
	t_n_l		*elem;

	if (!(elem = (t_n_l *)malloc(sizeof(t_n_l))))
		return (NULL);
	elem->num = content;
	elem->next = NULL;
	elem->back = NULL;
	return (elem);
}

void			add_elem(t_n_l **list, t_n_l *elem)
{
	if (*list != NULL)
	{
		(*list)->back = elem;
		elem->next = *list;
	}
	*list = elem;
}

t_n_l			*create_t_n_l(char **argv, int argc)
{
	t_n_l		*list;

	list = NULL;
	while (argc != 0)
	{
		add_elem(&list, create_elem(ft_atoi(argv[argc])));
		argc--;
	}
	return (list);
}
