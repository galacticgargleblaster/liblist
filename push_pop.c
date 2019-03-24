/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:46:49 by marvin            #+#    #+#             */
/*   Updated: 2019/03/23 22:39:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void					list_push_head(t_doubly_linked_list *list, void *element)
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
		list->head->next = container;
		container->prev = list->head;
		list->head = list->head->next;
	} 
	list->size++;
}

void					list_push_tail(t_doubly_linked_list *list, void *element)
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
		list->tail->prev = container;
		container->next = list->tail;
		list->tail = list->tail->prev;
	} 
	list->size++;
}

void					*list_pop_head(t_doubly_linked_list *list)
{
	void				*element;
	t_element_container *tmp;

	element = NULL;
	if (list_is_empty(list))
		return (NULL);
	else
	{
		element = list->head->element;
		tmp = list->head;
		list->head = list->head->prev;
		free(tmp);
		list->head->next = NULL;
		list->size--;
		return (element);
	} 
}

void					*list_pop_tail(t_doubly_linked_list *list)
{
	void				*element;
	t_element_container *tmp;

	element = NULL;
	if (list_is_empty(list))
		return (NULL);
	else
	{
		element = list->tail->element;
		tmp = list->tail;
		list->tail = list->tail->next;
		free(tmp);
		list->tail->prev = NULL;
		list->size--;
		return (element);
	} 
}
