/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:17:07 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/11 13:54:07 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_len(int index)
{
	int	len;

	len = 0;
	if (index <= 0)
	{
		len++;
	}
	while (index != 0)
	{
		len++;
		index = index / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	index;
	char	*str;

	len = ft_len(n);
	index = n;
	str = malloc(sizeof(char) * (len + 1));
	if (str == '\0')
		return (NULL);
	if (index < 0)
	{
		str[0] = '-';
		index = -index;
	}
	if (index == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (index != 0)
	{
		str[len] = index % 10 + '0';
		len--;
		index = index / 10;
	}
	return (str);
}

void	ft_collect_conter(t_data *my)
{
	my->i = 0;
	my->j = 0;
	while (my->map[my->i])
	{
		while (my->map[my->i][my->j])
		{
			if (my->map[my->i][my->j] == 'C')
				my->rescoll++;
			my->j++;
		}
		my->j = 0;
		my->i++;
	}
}

int	ft_locat_p(t_data *my)
{
	my->i = 0;
	my->j = 0;
	while (my->map[my->i])
	{
		while (my->map[my->i][my->j])
		{
			if (my->map[my->i][my->j] == 'P')
				return (0);
			my->j++;
		}
		my->j = 0;
		my->i++;
	}
	return (0);
}

void	ft_keys(int k, t_data *my)
{
	if (k == 53)
	{
		ft_printf("Quit!\n");
		free_all(my);
	}
	if (k == 0 || k == 123)
	{
		ft_moveleft(my);
		ft_print_img(my);
	}
	if (k == 2 || k == 124)
	{
		ft_moveright(my);
		ft_print_img(my);
	}
	if (k == 1 || k == 125)
	{
		ft_movedown(my);
		ft_print_img(my);
	}
	if (k == 13 || k == 126)
	{
		ft_move_up(my);
		ft_print_img(my);
	}
}
