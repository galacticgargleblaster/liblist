/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:46:49 by marvin            #+#    #+#             */
/*   Updated: 2019/03/20 14:50:05 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void					list_prepend(t_doubly_linked_list *list, void *element)
{
	t_element_container	*container;

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

void					list_append(t_doubly_linked_list *list, void *element)
{
	t_element_container	*container;

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
