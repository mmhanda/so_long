/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_b_utl_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:47:00 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/11 13:51:04 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_down_right_up(t_data *my, int k)
{
	if (k == 0)
	{
	my->map[my->i][my->j] = '0';
	my->map[my->i + 1][my->j] = 'P';
	my->eatencoll++;
	my->mouve_count++;
	}
	if (k == 1)
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j + 1] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (k == 2)
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i - 1][my->j] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (k == 3)
		free_all(my);
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
		ft_move_down_right_up(my, 0);
	if (my->map[my->i + 1][my->j] == 'F')
	{
		ft_printf("You died !\n");
		free_all(my);
		exit (0);
	}
	if (my->map[my->i + 1][my->j] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("You win !\n");
		free_all(my);
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
		ft_move_down_right_up(my, 1);
	if (my->map[my->i][my->j + 1] == 'F')
	{
		ft_printf("You died !\n");
		free_all(my);
		exit (0);
	}
	if (my->map[my->i][my->j + 1] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		free_all(my);
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
		ft_move_down_right_up(my, 2);
	if (my->map[my->i - 1][my->j] == 'F')
	{
		ft_printf("You died !\n");
		free_all(my);
		exit (0);
	}
	if (my->map[my->i - 1][my->j] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		free_all(my);
		exit (0);
	}
	return (0);
}

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
		free_all(my);
		exit (0);
	}
	if (my->map[my->i][my->j - 1] == 'F')
		ft_move_down_right_up(my, 3);
	return (0);
}
