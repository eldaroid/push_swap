/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:17:32 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:48:38 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delint(int n)
{
	int i;
	int len;
	int del;

	i = 0;
	del = 1;
	len = ft_digitcount(n);
	while (i < len - 1)
	{
		del = del * 10;
		i++;
	}
	return (del);
}
