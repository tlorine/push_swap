/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:03:00 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:14:10 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			write_itog(t_n_l **a, t_n_l **b, int c, int op)
{
	ft_putstr("\nsorted : ");
	if (sorted_stack(*a) == 0 && *b == NULL)
		color_text("[OK]\n", GREEN, c);
	else
		color_text("[KO]\n", RED, c);
	ft_putstr("\noperation : ");
	color_text(ft_itoa(op), GREEN, c);
	free_list(a);
}

void			command_use_2(t_n_l **a, t_n_l **b, char *commnd)
{
	if (ft_strcmp(commnd, "pb") == 0)
		push(a, b);
	else if (ft_strcmp(commnd, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(commnd, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(commnd, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void			command_use(t_n_l **a, t_n_l **b, char *commnd)
{
	if (ft_strcmp(commnd, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(commnd, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(commnd, "sa") == 0)
		swap(a);
	else if (ft_strcmp(commnd, "sb") == 0)
		swap(b);
	else if (ft_strcmp(commnd, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(commnd, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(commnd, "pa") == 0)
		push(b, a);
	else
		command_use_2(a, b, commnd);
}

t_c_f			*check_flag(char **ar, int c)
{
	t_c_f		*f;
	int			tmp;

	f = (t_c_f*)malloc(sizeof(t_c_f));
	f->t = ft_strncmp(ar[c - 1], "-s:", 3) == 0 ? ft_atoi(ar[c - 1] + 3) : 0;
	tmp = f->t == 0 ? 1 : 2;
	f->col = ft_strcmp(ar[c - tmp], "-c") == 0 ? 1 : 0;
	f->v = ft_strcmp(ar[(c - f->col) - tmp], "-v") == 0 ? 1 : 0;
	if ((f->fd = open("inst.txt", O_RDONLY)) == -1)
	{
		ft_putstr("error : flag error");
		return (0);
	}
	valid(ar, c - ((f->v + f->col) + (f->t == 0 ? 0 : 1)));
	system("reset");
	if (f->col == 1 && f->v != 1)
	{
		ft_putstr("\n error: there must be a flag in front of the -v\n");
		return (0);
	}
	return (f);
}

int				main(int c, char **ar)
{
	t_c_f		*f;
	t_n_l		*a;
	t_n_l		*b;
	int			op;
	char		*commnd;

	f = check_flag(ar, c);
	IN_VAR(a, b, op);
	a = create_t_n_l(ar, (c - ((f->v + f->col) + (f->t == 0 ? 0 : 1)) - 1));
	sort_id(a, b);
	while (get_next_line(f->fd, &commnd))
	{
		ft_putstr("\e[s");
		if (f->v == 1)
			write_vis(a, b, f->col);
		command_use(&a, &b, commnd);
		op++;
		f->v == 1 ? usleep(f->t) : usleep(0);
		ft_putstr("\e[u");
	}
	if (f->v == 1)
		write_vis(a, b, f->col);
	close(f->fd);
	write_itog(&a, &b, f->col, op);
	FREE_STACKS(free_list, a, b);
}
