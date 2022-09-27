/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:45:08 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 15:29:15 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	my_atoi(char *nptr)
{
	unsigned int	i;
	int				flag;
	int				out;

	if (!nptr)
		return (-1);
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	flag = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	out = -1;
	if (my_isdigit(nptr[i]))
		out = 0;
	while (my_isdigit(nptr[i]))
		out = (out * 10) + (nptr[i++] - 48);
	return ((int)(out * flag));
}

int	ft_intlen(int num)
{
	int		i;

	i = 0;
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	have_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcompare(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1 && !str2)
		return (1);
	if (!str1 && !str2)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(char *s)
{
	char	*p;
	int		i;

	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return ((char *)p);
}
