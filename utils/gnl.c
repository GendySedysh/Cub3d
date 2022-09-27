/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:52:43 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/20 21:40:12 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

static char	*rmd_rec(char *rmd)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!rmd)
		return (0);
	while (rmd[i] && rmd[i] != '\n')
		i++;
	if (!rmd[i])
	{
		free(rmd);
		return (0);
	}
	out = malloc(sizeof(char) * ((ft_strlen(rmd) - i) + 1));
	if (!(out))
		return (0);
	i++;
	while (rmd[i])
		out[j++] = rmd[i++];
	out[j] = '\0';
	free(rmd);
	return (out);
}

static char	*line_rec(char *str)
{
	int		i;
	char	*out;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	out = malloc(sizeof(char) * (i + 1));
	if (!(out))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

int	get_next_line(int fd, char **line)
{
	int				byte_readed;
	char			*buf;
	static char		*rmd;

	byte_readed = 1;
	if (fd < 0 || !line || BUFFER_SIZE == 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!next_line_char(rmd) && byte_readed != 0)
	{
		byte_readed = read(fd, buf, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(buf);
			return (-1);
		}
		buf[byte_readed] = '\0';
		rmd = str_join(rmd, buf);
	}
	free(buf);
	*line = line_rec(rmd);
	rmd = rmd_rec(rmd);
	if (byte_readed == 0 || !rmd)
		return (0);
	return (1);
}
