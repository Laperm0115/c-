typedef struct phone{
	unsigned char name[16];
	unsigned char number[16];
	struct phone* next;
}Phone_Data;
// FUNCTIONS

void Linked_list_remove(char *number);
int Linked_list_search(char *name);
void Linked_list_add(char *name, char *number,int save_flag);
int Test_Insert_pn_info(void);
int Insert_pn_info(void);
int File_save(char *,char*);
int File_remove_node(char *number);
int File_remove_all(void);
int File_load(void);
void Linkd_list_init(void);
void print_data(void);
