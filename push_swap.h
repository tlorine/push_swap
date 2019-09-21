/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:53:11 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/21 16:17:35 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

/*
**const_commands
*/
# define SA				1
# define SB				2
# define SS				3
# define PA				4
# define PB				5
# define RA				6
# define RB				7
# define RR				8
# define RRA			9
# define RRB			10
# define RRR			11
# define VOID			-1

/*
**  const_color
*/
# define RED			"\e[0;31m"
# define GREEN			"\e[0;32m"
# define YELLOW			"\e[0;33m"
# define BLUE			"\e[0;34m"

/*
**  macr
*/
# define IN_VAR(a, b, c) a = 0, b = 0, c = 0
# define PLUS_MIN(x, y) x = x + 1, y = y - 1;
# define END(a, b, fd) free(a), a = NULL, free(b), b = NULL, close(fd)
# define FREE_STACKS(f, a, b) f(&a), f(&b)
# define STEP_MED(b, t, i) b->num = t->num, t = t->next, i = i + 1;

/*
**  struct_list
*/
typedef struct			s_num_list
{
	int					num;
	int					id;
	struct s_num_list	*next;
	struct s_num_list	*back;
}						t_n_l;

typedef struct			s_mas_int
{
	int					*mas;
	int					size;
}						t_m_i;

typedef struct			s_split
{
	int					rev;
	int					count;
	int					middle;
}						t_split;

typedef struct			s_recurs_var
{
	int					max_elem;
	int					next_max_elem;
	int					p_e;
	int					m_e;
	int					min_elem;
}						t_r_v;

typedef struct			s_checker_flag
{
	int					v;
	int					col;
	int					t;
	int					fd;
}						t_c_f;

/*
**  commands_functions
*/
void					swap(t_n_l **list);
void					push(t_n_l **st_one, t_n_l **st_two);
void					rotate(t_n_l **stack);
void					reverse_rotate(t_n_l **stack);
int						use_command(t_n_l **a, t_n_l **b,
	int commandm, t_m_i *com);

/*
**  list_operation
*/
int						t_split_stack(t_n_l **a, t_n_l **b,
	int middle, t_m_i *com);
void					sort_mas(int *mas, int size);
int						count_list_elem(t_n_l *stack);
int						sorted_stack(t_n_l *stack_a);
void					free_list(t_n_l **stack);

/*
**  elem_operation
*/
t_m_i					*create_mas(t_n_l *list);
int						search_median(t_n_l *buffer);
int						search_median_count(t_n_l *stack_a, int count);
int						search_min_elem(t_n_l *stack);
int						search_max_elem(t_n_l *stack);
int						search_elem_poz(t_n_l *stack, int elem);
int						search_first_elem_poz(t_n_l *stack, int middle);
int						search_next_max_elem(t_n_l *stack,
	int max);
int						search_first_elem(t_n_l *stack, int middle);
int						search_first_elem_count(t_n_l *stack,
	int middle, int max, char s);

/*
**  main_function
*/
void					sort_id(t_n_l *stack_a, t_n_l *stack_b);
void					valid(char **argv, int argc);
t_n_l					*create_t_n_l(char **argv, int argc);

/*
**  sort_algoritm
*/
void					five_hundred_elem_sort(t_n_l **a,
	t_n_l **b, t_m_i *com);
void					hundred_elem_sort(t_n_l **stack_a,
	t_n_l **stack_b, t_m_i *com);
void					ten_elem_sort(t_n_l **stack_a,
	t_n_l **stack_b, t_m_i *com);
void					three_elem_sort(t_n_l **stack_a,
	t_n_l **stack_b, t_m_i *com);
void					tesa(t_n_l **stack_a, t_n_l **stack_b,
	int count, t_m_i *com);
void					tesb(t_n_l **stack_a, t_n_l **stack_b,
	int count, t_m_i *com);
void					recursive_sort(t_n_l **stack_a,
	t_n_l **stack_b, t_m_i *com);
void					recursive_push_a(t_n_l **stack_a,
	t_n_l **stack_b, t_m_i *com);

/*
**  checker_function
*/
void					write_vis(t_n_l *stack_a,
	t_n_l *stack_b, int on);
void					color_text(char *string, char *color, int on);

#endif
