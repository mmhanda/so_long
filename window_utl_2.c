/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utl_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:20:02 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/11 12:36:49 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sa(t_data *my)
{
	free_alll(my);
	printf("You Quit!\n");
	exit(0);
}

void	ft_print_img(t_data *my)
{
	mlx_clear_window(my->mlx_ptr, my->win_ptr);
	print_wall1(my);
	print_c(my);
	print_pp(my);
	print_e1(my);
}
