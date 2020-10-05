/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:20:28 by dmetallo          #+#    #+#             */
/*   Updated: 2020/10/04 18:15:19 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_free(t_stack **st)
{
	t_stack	*next;

	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}

int			info_free(t_info **s, int ret_val)
{
	if (*s && (*s)->a)
		stack_free(&(*s)->a);
	if (*s && (*s)->b)
		stack_free(&(*s)->b);
	if (*s)
		free(*s);
	return (ret_val);
}

void		put_error(t_info **s, int ret_val)
{
	ft_putstr("Error\n");
	info_free(s, ret_val);
	exit(ret_val);
}

int			st_set_tmp_cmds(t_info *s, t_stack *tmp_b)
{
	s->tmp_pl = get_node_place_i(s->a, tmp_b->val); // где в стэке а должна стоять ныняшняя цифра в стэке Б (возвращает индекс от 0 включительно до низу ) А ( 3 10 9 ) возвращает 2й индекс (типо val=1 должна быть) 3й внизу (до тройки)
	s->tmp_b = node_iter_to_up(s->len_b, tmp_b->i); // минимальное количество операций чтобы закинуть наверх
	s->tmp_a = node_iter_to_up(s->len_a, s->tmp_pl); // сколько операций  нужно сделать чтобы произвести пуш а и цифра встала на свое место
	return (node_b_to_a_count(s->tmp_a, s->tmp_b, s->tmp_pl)); //cколько всего необходимо комманд сделать для перекидывания из стэека Б в стэк А
}

void		st_copy_tmp_to_opt_cmds(t_info *s)
{
	s->opt_pl = s->tmp_pl;
	s->opt_b = s->tmp_b;
	s->opt_a = s->tmp_a;
}
