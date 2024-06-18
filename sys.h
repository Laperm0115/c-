typedef struct phone{
	unsigned char name[16];
	unsigned char number[16];
	struct phone* next;
}Phone_Data;
// FUNCTIONS

void Linked_list_remove(char *number);
void Linked_list_search(char *name);
void Linked_list_add(char *name, char *number);
int Insert_pn_info(void);
void Linkd_list_init(void);
void print_data(void);
