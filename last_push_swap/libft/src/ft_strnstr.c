/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:22:36 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:52:45 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char*)haystack);
	while ((i + 1) <= len && haystack[i] != '\0')
	{
		if (i + needle_len > len)
			return (NULL);
		if (ft_strncmp(needle, &haystack[i], needle_len) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
