/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:44:32 by marvin            #+#    #+#             */
/*   Updated: 2019/03/18 17:02:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

doubly_linked_list_t *new_doubly_linked_list()
{
	doubly_linked_list_t *list;

	list = malloc(sizeof(doubly_linked_list_t));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

element_container_t *new_doubly_linked_element_container()
{
	element_container_t *container;

	container = malloc(sizeof(element_container_t));
	container->element = NULL;
	container->next = NULL;
	container->prev = NULL;
	return (container);
}

void delete_doubly_linked_list(doubly_linked_list_t *list,
			   void del(void *element))
{
	element_container_t *tmp;

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