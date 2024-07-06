/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:39:30 by yeoshin           #+#    #+#             */
/*   Updated: 2024/07/04 11:41:21 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*object_new(t_object_type type, void *element, t_color reflect)
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
