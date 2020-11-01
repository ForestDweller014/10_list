#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mystruct.h"
   
int main() {
	struct session *curr_struct = NULL;
	srand(time(NULL));
	curr_struct = insert_front(curr_struct, "ForestDweller");
	curr_struct = insert_front(curr_struct, "xXSekushi_BlastXx");
	curr_struct = insert_front(curr_struct, "Gladiator153");
	curr_struct = insert_front(curr_struct, "~NoobSlayer~");
	curr_struct = insert_front(curr_struct, "BiggieSmalls");

	printf("Original list\n---------------------------------------------------------\n");
	print_list(curr_struct);

	curr_struct = remove_node(curr_struct, "Gladiator153");
	printf("List after removal of user \"Gladiator153\"\n---------------------------------------------------------\n");
	print_list(curr_struct);

	curr_struct = insert_front(curr_struct, "slash");
	printf("List after insertion of user \"slash\"\n---------------------------------------------------------\n");
	print_list(curr_struct);

	curr_struct = free_list(curr_struct);
	printf("List after freeing list\n---------------------------------------------------------\n");
	print_list(curr_struct);

	return 0;
}