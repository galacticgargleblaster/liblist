/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:46:49 by marvin            #+#    #+#             */
/*   Updated: 2019/03/14 13:46:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

int	list_is_empty(doubly_linked_list_t *list)
{
	return (list->head == NULL);
}

void					list_prepend(doubly_linked_list_t *list, void *element)
{
	doubly_linked_element_container_t	*container;

	container = new_doubly_linked_element_container();
	container->element = element;
	if (list_is_empty(list))
	{
		list->head = container;
		list->tail = container;
	}
	else
	{
		list->head->prev = container;
		list->head = list->head->prev;
	} 
	list->size++;
}

void					list_append(doubly_linked_list_t *list, void *element)
{
	doubly_linked_element_container_t	*container;

	container = new_doubly_linked_element_container();
	container->element = element;
	if (list_is_empty(list))
	{
		list->tail = container;
		list->head = container;
	} 
	else
	{
		list->tail->next = container;
		list->tail = list->tail->next;
	} 
	list->size++;
}

void	*get_element_at_index(doubly_linked_list_t *list, size_t index)
{
	doubly_linked_element_container_t *container;

	if (index > list->size)
		return (NULL);
	container = list->head;
	while (index--)
		container = container->next;
	return (container->element);
}