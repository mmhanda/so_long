/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:02:10 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/12 02:02:13 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd, char *line)
{
	char	*buf;
	int		ret;

	if (!line)
		line = ft_strdup("");
	buf = malloc(2);
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (free(buf), line);
}

int	ft_mapelines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	lines(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

int	valid_map(int fd, int i)
{
	if (fd == 1 && i == 1)
		return (1);
	return (printf("%s", "Bad map! > recheck ur map"), 0);
}

int	main(int ac, char **av)
{
	t_data	my;

	if (ac != 2)
		return (printf("error args numb"), 0);
	else
	{
		my.fd = checkext(av[1]);
		my.line = read_map(my.fd, my.line);
		my.map = ft_split(my.line, '\n');
		my.fd = check_map(my.map, my.line);
		my.nn = check_map22(my.line, my);
		if (valid_map(my.fd, my.nn) == 0)
			return (0);
		print_mape(&my);
	}
}
