/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:27:17 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:50:49 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double base, double exp)
{
	double	i;
	double	res;

	i = 0;
	res = 1;
	while (i < exp)
	{
		res = res * base;
		i++;
	}
	return (res);
}
