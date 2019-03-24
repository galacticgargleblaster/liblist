/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1967/08/25 00:00:00 by student           #+#    #+#             */
/*   Updated: 2019/03/23 22:10:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	An opinionated list implementation, in the questionable code style of
**	École 42.
**
**	      t_doubly_linked_list             t_element_container
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

typedef struct					s_element_container
{
	struct s_element_container	*next;
	struct s_element_container	*prev;
	void						*element;
}								t_element_container;

typedef struct					s_doubly_linked_list
{
	t_element_container			*head;
	t_element_container			*tail;
	size_t						size;
}								t_doubly_linked_list;

/*
**	https://en.wikipedia.org/wiki/List_(abstract_data_type)#Operations
*/

int								list_is_empty(t_doubly_linked_list *list);
void							list_push_head(
	t_doubly_linked_list *list, void *element);
void							list_push_tail(
	t_doubly_linked_list *list, void *element);
t_doubly_linked_list			*new_doubly_linked_list();
t_element_container				*new_doubly_linked_element_container();
void							delete_doubly_linked_list(
	t_doubly_linked_list *list, void delete_element(void *element));
void							*list_pop_head(t_doubly_linked_list *list);
void							*list_pop_tail(t_doubly_linked_list *list);


#endif
