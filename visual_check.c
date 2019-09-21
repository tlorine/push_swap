/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:59:59 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:07:16 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	color_text(char *string, char *color, int on)
{
	if (on)
		ft_putstr(color);
	ft_putstr(string);
	if (on)
		ft_putstr("\e[0m");
}

void	write_square(t_n_l *stack_a, t_n_l *stack_b, int on, int width)
{
	int	i;

	i = 0;
	color_text("| ", YELLOW, on);
	while (i < width - 4)
	{
		if (stack_a && stack_a->id > i)
			color_text("-", BLUE, on);
		else
			write(1, " ", 1);
		i++;
	}
	color_text(" |", YELLOW, on);
}

void	write_vis(t_n_l *stack_a, t_n_l *stack_b, int on)
{
	int	width;
	int	i;
	int	height;

	width = (count_list_elem(stack_a) + count_list_elem(stack_b) + 4);
	height = width - 4;
	while (height != 0)
	{
		write_square(stack_a, stack_b, on, width);
		ft_putstr("    ");
		write_square(stack_b, stack_a, on, width);
		write(1, "\n", 1);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
		height--;
	}
	i = 0;
}
