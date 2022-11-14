/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:11:23 by mhanda            #+#    #+#             */
/*   Updated: 2022/02/11 08:05:11 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_calloc(size_t nitems, size_t sizeitems)
{
	char			*ptr;
	unsigned int	k;

	k = nitems * sizeitems;
	ptr = malloc(k);
	if (ptr == 0)
		return (NULL);
	ft_memset(ptr, 0, k);
	return (ptr);
}

static void	ft_free(char **str, int k)
{
	while (k--)
		free(str[k]);
	free(str);
}

char	*ft_strdup(char *str)
{
	unsigned int	k;
	unsigned int	i;
	char			*p;

	i = 0;
	k = ft_strlen((char *)str) + 1;
	p = (char *)malloc(k * sizeof(char));
	if (!p)
		return (NULL);
	if (!str)
	{
		str[i] = '\0';
		return (str);
	}
	while (str && k-- > 0)
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}

static char	**subsrtings(char **str, char const *s, char c, int count)
{
	int	len;
	int	k;
	int	i;

	i = 0;
	len = 0;
	k = 0;
	while (s[i] && k < count)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		str[k++] = (char *)ft_calloc(sizeof(char), (len + 1));
		len = 0;
	}
	if (k > 0 && !str[k - 1])
	{
		ft_free(str, k - 1);
		return (0);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		len;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = -1;
	if (s == NULL)
		return (NULL);
	len = wdc(s, c);
	str = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!str)
		return (NULL);
	subsrtings(str, s, c, len);
	while (s[i] && j + 1 < len)
	{
		if (s[i] != c && ++j >= 0)
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
		while (s[i] == c && s[i++])
			k = 0;
	}
	return (str);
}
