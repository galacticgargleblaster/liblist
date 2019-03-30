
An opinionated list implementation, in the [questionable code style](http://nicjam.es/why-the-42-header-must-go/) of École 42.
	
	
		      t_doubly_linked_list             t_element_container
	
		+-------------------------+          +-------------+-------+
		|                         |          |               next +-----> NULL
		|                    head +--------->+   content           |
		|  size                   |          |               prev  |
		|                         |          +---------------^-----+
		|                    tail +----+                     |  |
		|                         |    |     +---------------+--v--+
		+-------------------------+    |     |               next  |
		                               |     |   content           |
		                               |     |               prev  |
		                               |     +---------------^-----+
		                               |                     |  |
		                               |     +---------------+--v--+
		                               |     |               next  |
		                               +---->+   content           |
		                                     |               prev +-----> NULL
		                                     +---------------------+
	
