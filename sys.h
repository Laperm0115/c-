typedef struct{
	unsigned char name[16];
	unsigned char pn[16];
}Phone_Data;
// FUNCTIONS

int Insert_new_pn(void);
void sys_init(void);
void print_data(void);
