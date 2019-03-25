/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:46:49 by marvin            #+#    #+#             */
/*   Updated: 2019/03/25 14:04:13 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**===========================================================================**
**	returns element at index "idx" with respect to the tail of the list
**===========================================================================**
*/

void					*list_get_index(t_doubly_linked_list *list, size_t idx)
{
	t_element_container	*tmp;

	if (list_is_empty(list) || idx > list->size - 1)
		return (NULL);
	tmp = list->tail;
	while (idx)
	{
		tmp = tmp->next;
		idx--;
	}
	return (tmp->element);
}
