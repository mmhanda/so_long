/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:03:20 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/12 21:03:22 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long x, int count)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (x >= 16)
	{
		count = ft_putptr(x / 16, count);
		count = ft_putptr(x % 16, count);
	}
	else
	{
		write (1, &tab[x], 1);
		count++;
	}
	return (count);
}
