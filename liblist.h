/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:42:25 by marvin            #+#    #+#             */
/*   Updated: 2019/03/14 13:45:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	An opinionated list implementation, in the questionable code style of École 42.
**
**
**	      doubly_linked_list_t             doubly_linked_element_container_t
**	                                                                              
**	+-------------------------+          +-------------+-------+     
**	|                         |          |               next +-----> NULL
**	|                    head +--------->+   content           |
**	|  size                   |          |               prev  |
**	|                         |          +---------------^-----+
**	|                    tail +----+                     |  |
**	|                         |    |     +---------------+--v--+
**	+-------------------------+    |     |               next  |
**	                               |     |   content           |
**	                               |     |               prev  |
**	                               |     +---------------^-----+
**	                               |                     |  |
**	                               |     +---------------+--v--+
**	                               |     |               next  |
**	                               +---->+   content           |
**	                                     |               prev +-----> NULL
**	                                     +---------------------+
**
*/

#ifndef LIBLIST_H
# define LIBLIST_H

#include <stdlib.h>

typedef struct	doubly_linked_element_container_s
{
	struct doubly_linked_element_container_s	*next;
	struct doubly_linked_element_container_s	*prev;
	void										*element;
}				doubly_linked_element_container_t;

typedef struct	doubly_linked_list_s
{
	doubly_linked_element_container_t			*head;
	doubly_linked_element_container_t			*tail;
	size_t							size;
}				doubly_linked_list_t;


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

#endif
