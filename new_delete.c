/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:44:32 by marvin            #+#    #+#             */
/*   Updated: 2019/03/20 14:50:06 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

t_doubly_linked_list *new_doubly_linked_list()
{
	t_doubly_linked_list *list;

	list = malloc(sizeof(t_doubly_linked_list));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

t_element_container *new_doubly_linked_element_container()
{
	t_element_container *container;

	container = malloc(sizeof(t_element_container));
	container->element = NULL;
	container->next = NULL;
	container->prev = NULL;
	return (container);
}

void delete_doubly_linked_list(t_doubly_linked_list *list,
			   void del(void *element))
{
	t_element_container *tmp;

	while (list->size)
	{
		del(list->tail->element);
		tmp = list->tail;
		list->tail = list->tail->prev;
		free(tmp);
		list->size--;
	}
	free(list);
}