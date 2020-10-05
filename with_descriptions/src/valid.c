/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:20:42 by dmetallo          #+#    #+#             */
/*   Updated: 2020/07/28 15:20:44 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(int val_i, char *val_c)
{
	char	*cur_val;
	int		res;

	res = 0;
	cur_val = ft_itoa(val_i);
	if (ft_strcmp(cur_val, val_c) == 0)
		res = 1;
	if (cur_val)
		free(cur_val);
	return (res);
}

int	is_not_dupl(t_stack *st, int val)
{
	while (st)
	{
		if (st->val == val)
			return (0);
		st = st->next;
	}
	return (1);
}

int	is_sort_info(t_info *s)
{
	t_stack	*st_a;
	int		last_val;

	if (s->b != NULL)
		return (0);
	st_a = s->a;
	last_val = st_a->val;
	while (st_a)
	{
		if (last_val > st_a->val)
			return (0);
		last_val = st_a->val;
		st_a = st_a->next;
	}
	return (1);
}
