/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:23:02 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:52:58 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buf;

	if (len + 1 == 0)
		return (NULL);
	if (s == NULL || &s[start] == NULL)
		return (NULL);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	ft_strncpy(buf, &s[start], len);
	buf[len] = 0;
	return (buf);
}
