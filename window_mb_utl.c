/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_mb_utl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:19:13 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/11 13:48:12 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_alll(t_data *my)
{
	free(my->line);
	free(my->map);
	mlx_destroy_image(my->mlx_ptr, my->img_1);
	mlx_destroy_image(my->mlx_ptr, my->img_e1);
	mlx_destroy_image(my->mlx_ptr, my->img_c);
	mlx_destroy_image(my->mlx_ptr, my->img_p);
}

int	free_all(t_data *my)
{
	free(my->line);
	free(my->map);
	mlx_destroy_image(my->mlx_ptr, my->img_1);
	mlx_destroy_image(my->mlx_ptr, my->img_0);
	mlx_destroy_image(my->mlx_ptr, my->img_p_1);
	mlx_destroy_image(my->mlx_ptr, my->img_p_2);
	mlx_destroy_image(my->mlx_ptr, my->img_p_3);
	mlx_destroy_image(my->mlx_ptr, my->img_e1);
	mlx_destroy_image(my->mlx_ptr, my->img_e2);
	mlx_destroy_image(my->mlx_ptr, my->img_c);
	mlx_destroy_image(my->mlx_ptr, my->img_f);
	exit (0);
	return (0);
}

void	print_wall1(t_data *my)
{
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	while (my->map[my->f])
	{
		while (my->map[my->f][my->j])
		{
			if (my->map[my->f][my->j] == '1')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_1, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}

void	print_e1(t_data *my)
{
	my->i = 0;
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	while (my->map[my->f])
	{
		while (my->map[my->f][my->j])
		{
			if (my->map[my->f][my->j] == 'E')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_e1, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}

void	print_c(t_data *my)
{
	my->i = 0;
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	while (my->map[my->f])
	{
		while (my->map[my->f][my->j])
		{
			if (my->map[my->f][my->j] == 'C')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_c, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}
