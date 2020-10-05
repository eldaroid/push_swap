/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:17:45 by dmetallo          #+#    #+#             */
/*   Updated: 2020/10/04 18:44:16 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_info	*sts;
	char	*cur_com;

	cur_com = NULL;
	sts = create_info(ac, av);
	sts->cmd_print = 0;
	if (sts->a == NULL)
		exit(info_free(&sts, 0));
	while (get_next_line(0, &cur_com))
	{
		cmd_apply_cnt(cur_com, 1, sts);
		if (cur_com)
			free(cur_com);
	}
	if (is_sort_info(sts))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (info_free(&sts, 0));
}
