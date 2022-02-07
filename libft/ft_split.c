/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:41:54 by lkasandr          #+#    #+#             */
/*   Updated: 2021/04/13 14:21:01 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_letter(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free_str(char **str, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		free(str[i]);
		i++;
	}
}

static char	**ft_strings(char *s, int word, char c, char **str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < word)
	{
		while (*s == c)
			s++;
		len = ft_letter(s, c);
		str[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[i])
		{
			ft_free_str(str, i);
			return (NULL);
		}
		j = 0;
		while (j < len)
			str[i][j++] = *s++;
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_word(s, c);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_strings(s, size, c, str);
	return (str);
}
