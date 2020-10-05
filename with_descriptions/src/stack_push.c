/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:20:07 by dmetallo          #+#    #+#             */
/*   Updated: 2020/07/28 15:20:09 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stack_push_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	last = get_last_node(*stack);
	last->next = new;
}

void			stack_push_front(t_stack **stack, t_stack *new)
{
	if (!(*stack))
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack			*stack_push_back_int(t_stack **stack, int val)
{
	t_stack *new;

	if (!(new = create_new_node(val)))
		return (NULL);
	stack_push_back(stack, new);
	return (*stack);
}
