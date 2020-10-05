/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:18:40 by dmetallo          #+#    #+#             */
/*   Updated: 2020/10/05 19:54:01 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_a_norm(t_info *s)
{
	int com;

	set_index(s->a);
	s->max_sort = get_max_sort(s->a);
	s->len_a = get_count_nodes(s->a);
	com = s->len_a - s->max_sort->i - s->max_sort->sort > 0 ?
		s->max_sort->i + s->max_sort->sort :
		ft_abs(s->len_a - s->max_sort->i - s->max_sort->sort);
	com = node_iter_to_up(s->len_a, com);
	cmd_apply_cnt(com > 0 ? "ra" : "rra", com, s);
}

void	st_a_to_b(t_info *s)
{
	t_stack *st_a;

	st_a = s->a;
	while (st_a && st_a->i != s->max_sort->i)
	{
		st_a = st_a->next;
		cmd_apply_cnt("pb", 1, s);
	}
}

void	node_b_to_a(t_info *s)
{
	s->tmp_b = ft_abs(s->opt_b);
	s->tmp_a = ft_abs(s->opt_a);
	while (((s->opt_b > 0 && s->opt_a > 0) || (s->opt_b < 0 &&
			s->opt_a < 0)) && s->tmp_b && s->tmp_a && s->opt_pl != -1)
	{
		cmd_apply_cnt(s->opt_b > 0 ? "rr" : "rrr", 1, s);
		s->tmp_b--;
		s->tmp_a--;
	}
	cmd_apply_cnt(s->opt_b > 0 ? "rb" : "rrb", s->tmp_b, s);
	if (s->opt_pl != -1)
		cmd_apply_cnt(s->opt_a > 0 ? "ra" : "rra", s->tmp_a, s);
	cmd_apply_cnt("pa", 1, s);
}

void	st_b_to_a(t_info *s)
{
	t_stack *tmp_b;
	int		min_cmds;
	int		cmds;

	while (s->b)
	{
		tmp_b = s->b;
		set_index(s->a);
		set_index(s->b);
		s->len_a = get_count_nodes(s->a);
		s->len_b = get_count_nodes(s->b);
		min_cmds = st_set_tmp_cmds(s, tmp_b);
		st_copy_tmp_to_opt_cmds(s);
		while (tmp_b)
		{
			cmds = st_set_tmp_cmds(s, tmp_b);
			if (cmds < min_cmds)
			{
				min_cmds = cmds;
				st_copy_tmp_to_opt_cmds(s);
			}
			tmp_b = tmp_b->next;
		}
		node_b_to_a(s);
	}
}

void	st_a_min_to_top(t_info *s)
{
	t_stack	*tmp_a;
	t_stack	*min_node;
	int		iter_to_up;

	tmp_a = s->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		min_node = tmp_a->val < min_node->val ? tmp_a : min_node;
		tmp_a = tmp_a->next;
	}
	s->len_a = get_count_nodes(s->a);
	set_index(s->a);
	iter_to_up = node_iter_to_up(s->len_a, min_node->i);
	cmd_apply_cnt(iter_to_up > 0 ? "ra" : "rra", iter_to_up, s);
}
