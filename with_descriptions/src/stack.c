/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:19:09 by dmetallo          #+#    #+#             */
/*   Updated: 2020/07/28 15:19:11 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*create_new_node(int val)
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack			*get_last_node(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

int				get_count_nodes(t_stack *st)
{
	int count;

	count = 0;
	while (st)
	{
		st = st->next;
		count++;
	}
	return (count);
}

static void		create_stack_a(int ac, char **av, t_info *s)
{
	int i;
	int cur_val;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (ft_strcmp(av[i], "-v") == 0)
			s->flag_v = 1;
		else if (ft_strcmp(av[i], "-c") == 0)
			s->flag_c = 1;
		else
		{
			cur_val = ft_atoi(av[i]);
			if (!is_valid_int(cur_val, av[i]) || !is_not_dupl(s->a, cur_val) ||
					!(stack_push_back_int(&s->a, cur_val)))
				put_error(&s, ft_free_array(ac == 2 ? av : NULL, 1));
		}
		i++;
	}
	ft_free_array(ac == 2 ? av : NULL, 1);
}

t_info			*create_info(int ac, char **av)
{
	t_info *s;

	if (!(s = (t_info*)malloc(sizeof(t_info))))
		put_error(&s, 1);
	s->a = NULL;
	s->b = NULL;
	s->flag_v = 0;
	s->flag_c = 0;
	s->cmds_cnt = 0;
	s->cmd_print = 0;
	create_stack_a(ac, av, s);
	return (s);
}
