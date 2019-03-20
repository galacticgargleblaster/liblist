/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns_out_this_does_not_matter.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1967/08/25 00:00:00 by student           #+#    #+#             */
/*   Updated: 4242/42/42 66:66:66 by studnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	An opinionated list implementation, in the questionable code style of
**	École 42.
**
**	      doubly_linked_list_t             element_container_t
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
*/

#ifndef LIBLIST_H
# define LIBLIST_H
# include <stdlib.h>

typedef struct					element_container_s
{
	struct element_container_s	*next;
	struct element_container_s	*prev;
	void						*element;
}								element_container_t;

typedef struct					doubly_linked_list_s
{
	element_container_t			*head;
	element_container_t			*tail;
	size_t						size;
}								doubly_linked_list_t;

int								list_is_empty(doubly_linked_list_t *list);
void							list_prepend(
	doubly_linked_list_t *list, void *element);
void							list_append(
	doubly_linked_list_t *list, void *element);
doubly_linked_list_t			*new_doubly_linked_list();
element_container_t				*new_doubly_linked_element_container();
void							delete_doubly_linked_list(
	doubly_linked_list_t *list, void del(void *element));

#endif
