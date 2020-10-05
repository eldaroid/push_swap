/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:57:34 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:51:27 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int r;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	r = 2;
	while (r * r <= nb)
	{
		if (r * r == nb)
			return (r);
		r++;
	}
	return (0);
}