/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:18:24 by dmetallo          #+#    #+#             */
/*   Updated: 2020/07/28 15:18:26 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_apply_s(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = tmp;
		return (1);
	}
	return (-1);
}

int	cmd_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		stack_push_back(stack, stack_pop_front(stack));
		return (1);
	}
	return (-1);
}

int	cmd_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		stack_push_front(stack, stack_pop_back(stack));
		return (1);
	}
	return (-1);
}

int	cmd_apply_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		stack_push_front(to, stack_pop_front(from));
		return (1);
	}
	return (-1);
}
