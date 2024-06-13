#include <stdio.h>
#include <string.h>
#include "sys.h"

Phone_Data data;
int Insert_new_pn(void)
{
	fprintf(stdout,"Insert Phone Name:__\b\b");
	fgets(data.name,sizeof(data.name),stdin);
	data.name[strlen(data.name) - 1 ] = '\0';
	return 0;
}

void print_data(void)
{
	printf("Phone Data[NAME]:%s\n",data.name);
	printf("Phone Data[PN]:%s\n",data.pn);
	return ;
}
void sys_init(void)
{
	memset(&data,0,sizeof(data));
	return ;
}
