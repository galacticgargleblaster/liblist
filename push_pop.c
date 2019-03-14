/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:46:49 by marvin            #+#    #+#             */
/*   Updated: 2019/03/14 14:26:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void					*list_pop_head(doubly_linked_list_t *list)
{
	void	*element;

	element = NULL;
	if (list_is_empty(list))
		return (NULL);
	else
	{
		element = list->head->element;
		list->head = list->head->prev;
		free(list->head->next);
		list->head->next = NULL;
		list->size--;
		return (element);
	} 
}

void					*list_pop_tail(doubly_linked_list_t *list)
{
	void	*element;

	element = NULL;
	if (list_is_empty(list))
		return (NULL);
	else
	{
		element = list->tail->element;
		list->tail = list->tail->next;
		free(list->tail->prev);
		list->tail->prev = NULL;
		list->size--;
		return (element);
	} 
}