#include "sys.h"
#include <stdio.h>
int main(void)
{
	Insert_pn_info();
	Insert_pn_info();
	print_data();

	Linked_list_remove("010-1234-1234");
	Linked_list_search("minsu");
	print_data();
	Linkd_list_init();
	return 0;
}
