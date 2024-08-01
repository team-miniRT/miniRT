/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:39:30 by yeoshin           #+#    #+#             */
/*   Updated: 2024/08/01 12:08:05 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*object_new(t_object_type type, void *element, t_vec reflect)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (new == NULL)
		exit(1);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->reflect = reflect;
	return (new);
}

void	object_addback(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_object	*object_last(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}
