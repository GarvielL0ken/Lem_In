
#include "../lem_in_js.h"

t_path 		*remove_path(t_path *current)
{
	t_path *remove;
	t_path *next;

	remove = current->next;
	next = current->next->next;
	free(remove->arr_path);
	free(remove);
	return (next);
}