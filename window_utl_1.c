/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utl_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:09:44 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/11 12:27:27 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moveleft(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i][my->j - 1] == '1')
		return (0);
	if (my->map[my->i][my->j - 1] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j - 1] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i][my->j - 1] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j - 1] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i][my->j - 1] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}

int	ft_moveright(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i][my->j + 1] == '1')
		return (0);
	if (my->map[my->i][my->j + 1] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j + 1] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i][my->j + 1] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j + 1] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i][my->j + 1] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}

int	ft_movedown(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i + 1][my->j] == '1')
		return (0);
	if (my->map[my->i + 1][my->j] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i + 1][my->j] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i + 1][my->j] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i + 1][my->j] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i + 1][my->j] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}

int	ft_move_up(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i - 1][my->j] == '1')
		return (0);
	if (my->map[my->i - 1][my->j] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i - 1][my->j] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i - 1][my->j] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i - 1][my->j] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i - 1][my->j] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}

void	ft_move_print_img(int send, t_data *my, int *i)
{
	if (send == 1)
	{
		ft_moveleft(my);
		ft_print_img(my);
		if (my->mouve_count != *i)
			ft_printf("%d\n", my->mouve_count);
	}
	if (send == 2)
	{
		ft_moveright(my);
		ft_print_img(my);
		if (my->mouve_count != *i)
			ft_printf("%d\n", my->mouve_count);
	}
	if (send == 3)
	{
		ft_movedown(my);
		ft_print_img(my);
		if (my->mouve_count != *i)
			ft_printf("%d\n", my->mouve_count);
	}
}
