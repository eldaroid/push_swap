/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:23:07 by vsanta            #+#    #+#             */
/*   Updated: 2020/10/05 19:53:01 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t start;
	size_t end;

	if (s == NULL)
		return (NULL);
	start = 0;
	if (s[0] == 0)
		return (ft_strnew(0));
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = start;
	while (s[end] != 0)
		end++;
	if (end == start)
		return (ft_strnew(0));
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t' || s[end] == 0)
		end--;
	return (ft_strsub(s, (unsigned int)start, end - start + 1));
}
