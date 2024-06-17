typedef struct{
	unsigned char name[16];
	unsigned char number[16];
}Phone_Data;
// FUNCTIONS

int Insert_pn_number(void);
int Insert_pn_name(void);
void sys_init(void);
void print_data(void);
