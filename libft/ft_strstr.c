/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:54:23 by lkasandr          #+#    #+#             */
/*   Updated: 2021/04/13 14:21:26 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str1, char *str2)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	if (!str1 && !str2)
		return (NULL);
	while (str1[++i])
	{
		if (str1[i] == str2[j])
		{
			while (str2[++j] && str1[++i])
			{
				if (str1[i] != str2[j])
					break ;
			}
			count = count + j;
			j = 0;
		}
	}
	if (count < ft_strlen(str2))
		return (NULL);
	return (str2);
}
