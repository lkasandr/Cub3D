/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:31:29 by lkasandr          #+#    #+#             */
/*   Updated: 2021/04/13 14:32:04 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	symb;
	char			*str;

	symb = (unsigned char)c;
	str = (char *)s;
	while (*str && !(*str == symb))
		str++;
	if (*str == symb)
		return (str);
	else
		return (NULL);
}
