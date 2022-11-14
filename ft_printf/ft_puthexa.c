/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:03:04 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/12 21:03:06 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int x, int nature, int count)
{
	char	*tab;

	if (nature == 0)
		tab = "0123456789abcdef";
	else if (nature == 1)
		tab = "0123456789ABCDEF";
	if (x >= 16)
	{
		count = ft_puthexa(x / 16, nature, count);
		count = ft_puthexa(x % 16, nature, count);
	}
	else
	{
		write (1, &tab[x], 1);
		count++;
	}
	return (count);
}
