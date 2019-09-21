/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:13:28 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:08:52 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorted_stack(t_n_l *stack_a)
{
	int min;

	while (stack_a != NULL)
	{
		min = search_min_elem(stack_a);
		if (stack_a->num != min)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int		middle_elem(t_n_l *stack, int middle)
{
	int i;

	i = 0;
	while (i < middle)
	{
		stack = stack->next;
		i++;
	}
	return (stack->num);
}

int		count_list_elem(t_n_l *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	sort_mas(int *mas, int size)
{
	int i;
	int i2;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		i2 = i;
		while (i2 < size)
		{
			if (mas[i] > mas[i2])
			{
				tmp = mas[i];
				mas[i] = mas[i2];
				mas[i2] = tmp;
			}
			i2++;
		}
		i++;
	}
}

t_m_i	*create_mas(t_n_l *list)
{
	t_m_i	*mas;
	int		i;

	i = 0;
	mas = (t_m_i *)malloc(sizeof(t_m_i));
	mas->size = count_list_elem(list);
	mas->mas = (int *)malloc(sizeof(int) * (mas->size));
	while (i < mas->size)
	{
		mas->mas[i] = list->num;
		list = list->next;
		i++;
	}
	return (mas);
}
