/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:48:21 by lkasandr          #+#    #+#             */
/*   Updated: 2021/04/13 14:20:41 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dec_len(int digit)
{
	int	count;

	count = 0;
	if (digit == 0)
		count = 1;
	if (digit < 0)
		count = 1;
	while (digit)
	{
		digit = digit / 10;
		count++;
	}
	return (count);
}
