/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_b_utl_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:17:04 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/12 00:58:16 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	saa(t_data *my)
{
	ft_printf("Quit !\n");
	free_all(my);
	exit (0);
}

int	key(int k, t_data *my)
{
	ft_keys(k, my);
	return (0);
}

void	ft_print_img(t_data *my)
{
	mlx_clear_window(my->mlx_ptr, my->win_ptr);
	print_wall1(my);
	print_0(my);
	print_c(my);
	print_p(my);
	print_f(my);
	if (my->rescoll != my->eatencoll || my->rescoll == 0)
		print_e1(my);
	else if (my->rescoll == my->eatencoll && my->rescoll != 0)
		print_e2(my);
	my->t = ft_itoa(my->mouve_count);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 10, 10, 65439, my->t);
	free(my->t);
}

void	my_path(t_data *my)
{
	my->path = "./image/wall64.xpm";
	my->img_1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/black_back.xpm";
	my->img_0 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/playerD.xpm";
	my->img_p_1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/playerR.xpm";
	my->img_p_2 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/playerU.xpm";
	my->img_p_3 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/cdoor1.xpm";
	my->img_e1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/dor1.xpm";
	my->img_e2 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/collect.xpm";
	my->img_c = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/enemy.xpm";
	my->img_f = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
}

void	print_mape(t_data *my)
{
	my->i = 0;
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	my->image_reminder = 0;
	my->mouve_count = 0;
	my->eatencoll = 0;
	my->mlx_ptr = mlx_init();
	my->win_ptr = mlx_new_window(my->mlx_ptr, ft_strlen(my->map[my->i]) * 64,
			ft_mapelines(my->map) * 64, "so_long");
	my_path(my);
	ft_print_img(my);
	mlx_hook(my->win_ptr, 2, 0, key, my);
	mlx_hook(my->win_ptr, 17, 0, saa, my);
	mlx_loop_hook(my->mlx_ptr, print_p, my);
	ft_collect_conter(my);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 10, 10, 65439, my->t);
	mlx_loop(my->mlx_ptr);
}
