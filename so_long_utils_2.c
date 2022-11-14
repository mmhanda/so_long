/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:24:35 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/12 01:36:31 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != 0)
	{
		i++;
	}
	return (i);
}

int	checkext(char *av)
{
	int	fd;

	fd = open (av, O_RDONLY);
	if (fd == -1)
	{
		perror("its not .ber a retard");
		exit (0);
	}
	if (ft_strstr(av, ".ber"))
		return (fd);
	else
	{
		perror("its not .ber a retard");
		exit (0);
	}
	return (fd);
}

int	check_map(char **map, char *line)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (ft_mapelines(map) != lines(line))
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1')
				return (0);
			if (map[i][ft_strlen(map[i]) - 1] != '1'
				|| map[ft_mapelines(map) - 1][j] != '1')
				return (0);
			if (ft_strlen(map[i]) - 1
				!= ft_strlen(map[ft_mapelines(map) - 1]) - 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map22(char *line, t_data g)
{
	g.i1 = 0;
	g.e1 = 0;
	g.c1 = 0;
	g.p1 = 0;
	g.ff1 = 0;
	while (line[g.i1])
	{
		if (line[g.i1] != 'P' && line[g.i1] != 'C' && line[g.i1] != 'E'
			&& line[g.i1]
			!= '1' && line[g.i1] != '0' && line[g.i1] != '\n'
			&& line[g.i1] != 'F')
			return (0);
		if (line[g.i1] == 'C')
			g.c1++;
		if (line[g.i1] == 'E')
			g.e1++;
		if (line[g.i1] == 'P')
			g.p1++;
		if (line[g.i1] == 'F')
			g.ff1++;
		g.i1++;
	}
	if (g.p1 != 1 || g.c1 == 0 || g.e1 == 0 || g.ff1 == 0)
		return (0);
	return (1);
}

int	check_map2(char *line)
{
	t_game	g;

	g.i = 0;
	g.e = 0;
	g.c = 0;
	g.p = 0;
	while (line[g.i])
	{
		if (line[g.i] != 'P' && line[g.i] != 'C' && line[g.i] != 'E'
			&& line[g.i]
			!= '1' && line[g.i] != '0' && line[g.i] != '\n')
			return (0);
		if (line[g.i] == 'C')
			g.c++;
		if (line[g.i] == 'E')
			g.e++;
		if (line[g.i] == 'P')
			g.p++;
		g.i++;
	}
	if (g.p != 1 || g.c == 0 || g.e == 0)
		return (0);
	return (1);
}
