/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:20:58 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:51:34 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s[i] == c)
		return ((char*)&s[i]);
	while (s[i] != 0)
	{
		if (s[i + 1] == c)
			return ((char*)&s[i + 1]);
		i++;
	}
	return (NULL);
}
