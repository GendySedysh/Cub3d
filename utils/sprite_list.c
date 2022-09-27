/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:07:39 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/26 17:41:34 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

t_sprite	*ft_create_elem(int x, int y)
{
	t_sprite	*elem;

	elem = (t_sprite *)malloc(sizeof(t_sprite));
	if (!elem)
	{
		perror("SPRITE MALLOC error");
		exit (0);
	}
	elem->next = NULL;
	elem->x = x;
	elem->y = y;
	return (elem);
}

void	ft_list_push_front(t_sprite **begin_list, int x, int y)
{
	t_sprite	*n_elem;

	n_elem = ft_create_elem(x, y);
	n_elem->next = *begin_list;
	*begin_list = n_elem;
}

void	delete_list(t_sprite *head)
{
	t_sprite	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

t_sprite	*sort(t_sprite *root)
{
	t_sprite	*new_root;
	t_sprite	*node;
	t_sprite	*current;

	new_root = NULL;
	while (root != NULL)
	{
		node = root;
		root = root->next;
		if (new_root == NULL || node->y > new_root->y)
		{
			node->next = new_root;
			new_root = node;
		}
		else
		{
			current = new_root;
			while (current->next != NULL && !(node->y > current->next->y))
				current = current->next;
			node->next = current->next;
			current->next = node;
		}
	}
	return (new_root);
}
