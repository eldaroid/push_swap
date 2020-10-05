/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:18:05 by dmetallo          #+#    #+#             */
/*   Updated: 2020/07/28 15:18:07 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		print(char *str, char *color1, char *color2, int b)
{
	if (b)
		ft_putstr(color1);
	ft_putstr(str);
	if (b)
		ft_putstr(color2);
}

void			print_stack(t_info *s)
{
	t_stack *st_a;
	t_stack *st_b;

	st_a = s->a;
	st_b = s->b;
	print("\tA\t|\tB\n\t\t|\t\n", G, END, s->flag_c);
	while (st_a || st_b)
	{
		if (st_a)
		{
			print("\t", Y, Y, s->flag_c);
			ft_putnbr(st_a->val);
		}
		else
			print("\t-", R, END, s->flag_c);
		print("\t|\t", G, Y, s->flag_c);
		if (st_b)
			ft_putnbr(st_b->val);
		else
			print("-", R, END, s->flag_c);
		ft_putchar('\n');
		st_a = st_a ? st_a->next : NULL;
		st_b = st_b ? st_b->next : NULL;
	}
	ft_putchar('\n');
}

static int		cmd_apply(char *com, t_info *s)
{
	int	len;
	int	res;

	len = ft_strlen(com);
	res = 0;
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'a'))
		res = cmd_apply_s(&s->a);
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'b'))
		res = cmd_apply_s(&s->b);
	if (len == 2 && com[0] == 'p' && com[1] == 'a')
		res = cmd_apply_p(&s->b, &s->a);
	if (len == 2 && com[0] == 'p' && com[1] == 'b')
		res = cmd_apply_p(&s->a, &s->b);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'a'))
		res = cmd_apply_r(&s->a);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'b'))
		res = cmd_apply_r(&s->b);
	if (len == 3 && com[0] == 'r' && com[1] == 'r' &&
		(com[2] == 'r' || com[2] == 'a'))
		res = cmd_apply_rr(&s->a);
	if (len == 3 && com[0] == 'r' && com[1] == 'r' &&
		(com[2] == 'r' || com[2] == 'b'))
		res = cmd_apply_rr(&s->b);
	return (res == 0 ? 0 : 1);
}

void			cmd_apply_cnt(char *com, int cnt, t_info *s)
{
	int	i;

	i = ft_abs(cnt);
	while (i)
	{
		if (cmd_apply(com, s))
		{
			if (s->cmd_print)
			{
				print(com, B, END, s->flag_c);
				ft_putchar('\n');
			}
			if (s->flag_v)
				print_stack(s);
			s->cmds_cnt++;
		}
		else
			put_error(&s, 0);
		i--;
	}
}
