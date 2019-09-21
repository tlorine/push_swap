/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:38:04 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:12:18 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		search_min_next_lem(t_n_l *stack, int min)
{
	int elem;

	if (stack)
		elem = stack->num;
	while (stack)
	{
		if (elem > stack->num && stack->num != min)
			elem = stack->num;
		stack = stack->next;
	}
	return (elem);
}

void	search_command(t_m_i *c, int i, int fd)
{
	if (c->mas[i] == RR)
		ft_putstr_fd("rr\n", fd);
	else if (c->mas[i] == RRR)
		ft_putstr_fd("rrr\n", fd);
	else if (c->mas[i] == RA)
		ft_putstr_fd("ra\n", fd);
	else if (c->mas[i] == RB)
		ft_putstr_fd("rb\n", fd);
	else if (c->mas[i] == SA)
		ft_putstr_fd("sa\n", fd);
	else if (c->mas[i] == SB)
		ft_putstr_fd("sb\n", fd);
	else if (c->mas[i] == SS)
		ft_putstr_fd("ss\n", fd);
	else if (c->mas[i] == PA)
		ft_putstr_fd("pa\n", fd);
	else if (c->mas[i] == PB)
		ft_putstr_fd("pb\n", fd);
	else if (c->mas[i] == RRB)
		ft_putstr_fd("rrb\n", fd);
	else if (c->mas[i] == RRA)
		ft_putstr_fd("rra\n", fd);
}

int		optim_command(t_m_i *c, int i, int fd)
{
	if (i + 1 < c->size && c->mas[i] == RA && c->mas[i + 1] == RB)
		ft_putstr_fd("rr\n", fd);
	else if (i + 1 < c->size && c->mas[i] == RB && c->mas[i + 1] == RA)
		ft_putstr_fd("rr\n", fd);
	else if (i + 1 < c->size && c->mas[i] == RRA && c->mas[i + 1] == RRB)
		ft_putstr_fd("rrr\n", fd);
	else if (i + 1 < c->size && c->mas[i] == RRB && c->mas[i + 1] == RRA)
		ft_putstr_fd("rrr\n", fd);
	else if (i + 1 < c->size && c->mas[i] == SA && c->mas[i + 1] == SB)
		ft_putstr_fd("ss\n", fd);
	else if (i + 1 < c->size && c->mas[i] == SB && c->mas[i + 1] == SA)
		ft_putstr_fd("ss\n", fd);
	else if (i + 1 < c->size && c->mas[i] == RA && c->mas[i + 1] == RRA)
		i = i + 1;
	else if (i + 1 < c->size && c->mas[i] == RRA && c->mas[i + 1] == RA)
		i = i + 1;
	else
		return (0);
	return (1);
}

void	write_command(t_m_i *c, int fd)
{
	int i;

	i = 0;
	while (i < c->size)
	{
		if (optim_command(c, i, fd) == 0)
			search_command(c, i, fd);
		else
			i++;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_n_l	*stack_a;
	t_n_l	*stack_b;
	t_m_i	*c;
	int		count_elem;
	int		fd;

	fd = open("inst.txt", O_TRUNC | O_CREAT | O_WRONLY);
	IN_VAR(stack_a, stack_b, count_elem);
	valid(argv, argc);
	c = (t_m_i *)malloc(sizeof(t_m_i));
	stack_a = create_t_n_l(argv, argc - 1);
	count_elem = count_list_elem(stack_a);
	c->mas = (int *)malloc(sizeof(int) * (count_elem * count_elem) + 1);
	c->size = 0;
	if (count_elem >= 350 && sorted_stack(stack_a))
		five_hundred_elem_sort(&stack_a, &stack_b, c);
	else if (count_elem > 5 && sorted_stack(stack_a))
		hundred_elem_sort(&stack_a, &stack_b, c);
	else if (count_elem > 3 && sorted_stack(stack_a))
		ten_elem_sort(&stack_a, &stack_b, c);
	else if (sorted_stack(stack_a))
		three_elem_sort(&stack_a, &stack_b, c);
	write_command(c, fd);
	END(c->mas, c, fd);
	free_list(&stack_a);
}
