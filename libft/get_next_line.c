/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:33:52 by lkasandr          #+#    #+#             */
/*   Updated: 2021/04/22 22:41:33 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **arr)
{
	if (*arr)
		free(*arr);
	*arr = NULL;
	return (-1);
}

static char	*fill_tmp(char *ost)
{
	char		*tmp;

	if (ost)
	{
		tmp = ft_strdup(ost);
		ft_free(&ost);
	}
	else
	{
		tmp = (char *)malloc(sizeof(char));
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	return (tmp);
}

static char	*use_tmp(char *tmp, char *buf)
{
	char		*arr;

	arr = ft_strdup(tmp);
	ft_free(&tmp);
	tmp = ft_strjoin(arr, buf);
	ft_free(&arr);
	return (tmp);
}

static int	count_i(char *tmp)
{
	int			i;

	i = 0;
	if (tmp[i])
	{
		while (tmp[i])
		{
			if (tmp[i] == '\n')
				break ;
			i++;
		}
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int			r;
	char		*buf;
	char		*tmp;
	char		*eol;
	static char	*ost = NULL;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = read(fd, NULL, 0);
	if (!buf || fd < 0 || BUFFER_SIZE <= 0 || !line || (r < 0))
		return (ft_free(&ost) * ft_free(&buf) * (-1));
	tmp = fill_tmp(ost);
	eol = NULL;
	r = 1;
	while (!eol && (r > 0))
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		eol = ft_strchr(buf, '\n');
		tmp = use_tmp(tmp, buf);
	}
	*line = ft_substr(tmp, 0, count_i(tmp));
	ost = ft_substr(tmp, count_i(tmp) + 1, ft_strlen(tmp) - count_i(tmp));
	if (r || ft_strlen(ost) || tmp[count_i(tmp)] == '\n')
		return (ft_free(&tmp) * ft_free(&buf));
	return (ft_free(&tmp) * ft_free(&buf) * ft_free(&ost) * 0);
}
