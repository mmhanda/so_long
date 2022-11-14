/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:02:39 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/12 02:02:40 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"

typedef struct var
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
	int	f;
	int	ff;
}t_game;

typedef struct s_data
{
	void	*img_p;
	int		image_reminder;
	int		chang_image_2;
	int		chang_image_3;
	void	*img_1;
	void	*img_p_1;
	void	*img_p_2;
	void	*img_p_3;
	void	*img_f;
	void	*img_c;
	void	*img_e1;
	void	*img_e2;
	void	*img_0;
	char	*t;
	int		i1;
	int		j1;
	int		c1;
	int		e1;
	int		p1;
	int		f1;
	int		ff1;
	int		h;
	int		w;
	int		i;
	int		x;
	int		y;
	int		n;
	int		nn;
	int		fd;
	int		j;
	int		f;
	int		rescoll;
	int		eatencoll;
	int		mouve_count;
	char	*addr;
	char	*path;
	void	*img;
	char	*line;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*imgb;
}t_data;

void	my_path(t_data *my);
void	ft_collect_conter(t_data *my);
void	ft_keys(int k, t_data *my);
int		key(int k, t_data *my);
char	*ft_itoa(int n);
void	ft_print_img(t_data *my);
int		ft_move_up(t_data *my);
int		ft_moveright(t_data *my);
int		ft_movedown(t_data *my);
void	print_e2(t_data *my);
void	print_f(t_data *my);
void	print_0(t_data *my);
int		print_p(t_data *my);
void	print_slow_img(t_data *my);
void	print_pp(t_data *my);
int		ft_locat_p(t_data *my);
int		sa(t_data *my);
void	ft_move_print_img(int send, t_data *my, int *i);
int		ft_move_up(t_data *my);
void	ft_print_img(t_data *my);
int		ft_movedown(t_data *my);
int		ft_moveright(t_data *my);
int		ft_moveleft(t_data *my);
void	free_alll(t_data *my);
int		free_all(t_data *my);
void	print_c(t_data *my);
void	print_e1(t_data *my);
void	print_wall1(t_data *my);
int		lines(char *line);
int		check_map2(char *line);
int		check_map22(char *line, t_data g);
int		check_map(char **map, char *line);
int		checkext(char *av);
int		ft_strlen(char *c);
void	*ft_memset(void *str, int c, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *c);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *str);
char	**ft_split(char const *s, char c);
int		wdc(char const *s, char c);
char	*ft_strstr(const char *s, const char *tofind);
void	print_mape(t_data *my);
int		ft_mapelines(char **map);
int		ft_valid_map(int fd, int i);
#endif
