/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:46:49 by marvin            #+#    #+#             */
/*   Updated: 2019/03/25 20:20:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**===========================================================================**
**	returns a shallow copy
**===========================================================================**
*/

t_doubly_linked_list	*list_copy(const t_doubly_linked_list *list)
{
	t_doubly_linked_list	*new_list;
	t_element_container		*tmp;

	new_list = new_doubly_linked_list();
	tmp = list->tail;

	while (tmp)
	{
		list_push_tail(new_list, tmp->element);
		tmp = tmp->next;
	}
	return (new_list);
}