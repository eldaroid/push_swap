/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:30:17 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:49:35 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long int val, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (val < 0)
	{
		if (base == 10)
			neg = 1;
		val *= -1;
	}
	while (ft_pow(base, i) - 1 < val)
		i++;
	nbr = ft_strnew(i);
	while (i-- > 0)
	{
		nbr[i + neg] = (val % base) + (val % base > 9 ? 'A' - 10 : '0');
		val = val / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
