/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:33:00 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/24 22:53:52 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	my_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	my_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	nswe_check(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '2')
		return (1);
	return (0);
}
