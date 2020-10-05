/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:17:38 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:48:42 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitcount(long long int number)
{
	int count;

	count = (number == 0) ? 1 : 0;
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}
