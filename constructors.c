/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:44:32 by marvin            #+#    #+#             */
/*   Updated: 2019/03/14 13:45:29 by marvin           ###   ########.fr       */
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

static doubly_linked_element_container_t *new_doubly_linked_element_container()
{
	doubly_linked_element_container_t *container;

	container = malloc(sizeof(doubly_linked_element_container_t));
	container->element = NULL;
	container->next = NULL;
	container->prev = NULL;
}

void list_free(doubly_linked_list_t *list,
			   void del(void *element))
{
	doubly_linked_list_t *tmp;

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