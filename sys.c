#include <stdio.h>
#include <string.h>
#include "sys.h"

Phone_Data data;
int Insert_pn_number(void)
{
	fprintf(stdout,"Phone number ex) 010-0000-0000\n");
	fprintf(stdout,"[Insert]:____\b\b\b\b");
	fgets(data.number,sizeof(data.number),stdin);
	data.number[strlen(data.number) - 1 ] = '\0';
	return 0;
}
int Insert_pn_name(void)
{
	fprintf(stdout,"Name ex) Minsu\n");
	fprintf(stdout,"[Insert]:_____\b\b\b\b\b");
	fgets(data.name,sizeof(data.name),stdin);
	data.name[strlen(data.name) - 1 ] = '\0';
	return 0;
}

void print_data(void)
{
	printf("Phone Data[NAME]:%s\n",data.name);
	printf("Phone Data[NUMBER]:%s\n",data.number);
	return ;
}
void sys_init(void)
{
	memset(&data,0,sizeof(data));
	return ;
}
