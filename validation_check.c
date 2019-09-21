/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:04:26 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:11:54 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_arg(char **argv, int argc)
{
	t_n_l *stack;
	t_n_l *new;
	t_n_l *save;

	stack = create_t_n_l(argv, argc - 1);
	save = stack;
	new = stack;
	while (new)
	{
		stack = new;
		stack = stack->next;
		while (stack)
		{
			if (new->num == stack->num)
			{
				ft_putstr("\nerror : the same number cannot be on the stack\n");
				exit(1);
			}
			stack = stack->next;
		}
		new = new->next;
	}
	free_list(&save);
}

void	perepol_check(char **argv, int argc)
{
	t_n_l		*stack;
	t_n_l		*save;
	char		*num;
	int			i;

	i = 1;
	stack = create_t_n_l(argv, argc - 1);
	save = stack;
	while (stack)
	{
		num = ft_itoa(stack->num);
		if (ft_strcmp(argv[i], num) != 0)
		{
			ft_putstr("\nerror: the number is too big\n");
			exit(1);
		}
		if (num)
			num = ft_strdel(&num);
		stack = stack->next;
		i++;
	}
	free_list(&save);
}

void	num_check(char **argv, int argc)
{
	int i;
	int n;

	i = 1;
	n = 0;
	while (i != argc)
	{
		if (argv[i][n] == '-' && argv[i][n + 1] != '\0')
			n++;
		while ((argv[i][n] && (argv[i][n] >= '0' && argv[i][n] <= '9')))
			n++;
		if (argv[i][n] != '\0')
		{
			ft_putstr("\nerror: bad arguments\n");
			ft_putstr("\nexample: ./push_swap num1 num2 num3 | \
			./checker num1 num2 num3 -v -c s:150000 \n");
			ft_putstr("\n -v [visual]\n -c [color visual]\n \
			-s:NUM [program speed : recommended speed 15000] \n");
			exit(1);
		}
		i++;
		n = 0;
	}
}

void	valid(char **argv, int argc)
{
	int i;
	int n;

	i = 1;
	n = 0;
	if (argc < 2)
	{
		write(1, "\nerror: no arguments to sort\n", 29);
		exit(1);
	}
	num_check(argv, argc);
	perepol_check(argv, argc);
	double_arg(argv, argc);
}
