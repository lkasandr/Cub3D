/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:48:37 by lkasandr          #+#    #+#             */
/*   Updated: 2021/04/19 17:50:41 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	if (n_len > ft_strlen(haystack) || n_len > len)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j] && (i + j) < len)
			j++;
		if (j == n_len)
			return (((char *)haystack) + i);
		i++;
	}
	return (NULL);
}
