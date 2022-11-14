/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:02:58 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/12 02:03:00 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_pp(t_data *my)
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
			if (my->map[my->f][my->j] == 'P')
			{
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_p, my->x, my->y);
			}
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
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

int	key(int k, t_data *my)
{
	int	i;

	i = my->mouve_count;
	if (k == 53)
	{
		ft_printf("You Quit!\n");
		free_alll(my);
		exit (0);
	}
	if (k == 0 || k == 123)
		ft_move_print_img(1, my, &i);
	if (k == 2 || k == 124)
		ft_move_print_img(2, my, &i);
	if (k == 1 || k == 125)
		ft_move_print_img(3, my, &i);
	if (k == 13 || k == 126)
	{
		ft_move_up(my);
		ft_print_img(my);
		if (my->mouve_count != i)
			ft_printf("%d\n", my->mouve_count);
	}
	return (0);
}

void	print_mape(t_data *my)
{
	my->i = 0;
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	my->mouve_count = 0;
	my->eatencoll = 0;
	my->mlx_ptr = mlx_init();
	my->win_ptr = mlx_new_window(my->mlx_ptr, ft_strlen(my->map[my->i]) * 64,
			ft_mapelines(my->map) * 64, "so_long");
	my->path = "./image/wall64.xpm";
	my->img_1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/9.xpm";
	my->img_p = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/dor1.xpm";
	my->img_e1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/collect.xpm";
	my->img_c = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	ft_print_img(my);
	mlx_hook(my->win_ptr, 2, 0, key, my);
	ft_collect_conter(my);
	mlx_hook(my->win_ptr, 17, 0, sa, my);
	mlx_loop(my->mlx_ptr);
}
