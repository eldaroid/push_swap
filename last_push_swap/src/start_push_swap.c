/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:15:03 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 20:20:24 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_info *s)
{
	if (s->a->val > s->a->next->val &&
		s->a->val < s->a->next->next->val)
		cmd_apply_cnt("sa", 1, s);
	else if (s->a->val > s->a->next->next->val)
		cmd_apply_cnt("ra", 1, s);
}

static void	sort_five(t_info *s)
{
	if (s->max_sort->sort < 3)
	{
		cmd_apply_cnt("pb", 2, s);
		sort_three(s);
	}
	else
		st_a_to_b(s);
	st_b_to_a(s);
	st_a_min_to_top(s);
}

static void	sort_other(t_info *s)
{
	st_a_to_b(s);
	st_b_to_a(s);
	st_a_min_to_top(s);
}

int			main(int ac, char **av)
{
	t_info *s;

	s = create_info(ac, av);
	if (!s->a)
		exit(info_free(&s, 0));
	s->cmd_print = 1;
	s->len_a = get_count_nodes(s->a);
	st_a_norm(s);
	if (s->len_a == 3)
		sort_three(s);
	else if (s->len_a == 5)
		sort_five(s);
	else
		sort_other(s);
	return (info_free(&s, 0));
}
