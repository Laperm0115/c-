#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"

#define NAME_LEN 3
#define NUMBER_LEN 13

Phone_Data *head;
Phone_Data *tail;

void Linked_list_remove(char *number)
{
	Phone_Data *cur,*prev;
	cur = prev = head;

	for(; cur; cur = cur->next)
	{
		if(strcmp(cur->number,number) == 0)
		{
			if(cur == head)
			{
				head = cur->next;
				cur->next = NULL;
				free(cur);

				printf("Deleted Data!!\n");
				return ;
			}
			else
			{
				prev->next = cur->next;
				cur->next = NULL;
				free(cur);

				printf("Deleted Data!!\n");
				return ;
			}
		}
	}
	printf("No data Can't delete...\n");
	return ;
}


void Linked_list_search(char *name)
{
	Phone_Data *cur = head;

	for(; cur; cur = cur->next)
	{
		if(strcmp(cur->name,name) == 0)
		{
			printf("Found Data!!\n");
			printf("Found Data[NAME]:%s\n",cur->name);
			printf("Found Data[NUMBER]:%s\n",cur->number);
			return;
		}
	}
	printf("Not Found Data...\n");
	return ;
}

void Linked_list_add(char *name, char *number)
{
	Phone_Data *n_node;

	n_node = (Phone_Data *)malloc(sizeof(Phone_Data));
	strcpy(n_node->name,name);
	strcpy(n_node->number,number);
	n_node->next = NULL;

	if(head == NULL)
	{
		head = n_node;
		head->next = NULL;
	}
	else
		tail->next = n_node;

	tail = n_node;
	File_save(name,number);
	return ;
}

int File_save(char *name, char* number)
{
	FILE *fp;
	fp = fopen("Storage.txt","a");
	//fseek(fp,0,SEEK_END);
	fprintf(fp,"Name: %s Phone number: %s\n", name, number);
	fclose(fp);
}
int File_remove(void)
{
	const char* filename = "Storage.txt";
	remove(filename);
}
int File_store(void)
{
	FILE *fp;
	char name[16];
	char number[16];
	fp = fopen("Storage.txt","r");
	fscanf(fp,"Name: %s Phone number: %s\n",name,number);
	printf("FILE STORE!! %s %s\n",name,number);
	fclose(fp);
}
int Insert_pn_info(void)
{
	char number[16] = {0,};
	char name[16] = {0,};

	fprintf(stdout,"Name ex) Minsu\n");
	fprintf(stdout,"[Insert]:_____\b\b\b\b\b");
	fgets(name,sizeof(name),stdin);
	
	fprintf(stdout,"Phone number ex) 010-0000-0000\n");
	fprintf(stdout,"[Insert]:____\b\b\b\b");
	fgets(number,sizeof(number),stdin);
	
	if(strlen(name) < NAME_LEN || strlen(number) < NUMBER_LEN)
	{
		fprintf(stdout,"\n[ERROR] INSERT INFO LENGTH IS SHORT!!\n");
		return -1;
	}

	number[strlen(number) - 1 ] = '\0';
	name[strlen(name) - 1 ] = '\0';

	Linked_list_add(name,number);
	return 0;
}

void print_data(void)
{
	Phone_Data *cur = head;
	const char *format = "-----------------------";

	printf("%s\n",format);
	for(; cur; cur = cur->next)
	{
		printf("Phone Data[NAME]:%s\n",cur->name);
		printf("Phone Data[NUMBER]:%s\n",cur->number);
	}
	printf("%s\n",format);
	return ;
}

void Linkd_list_init(void)
{
	Phone_Data *cur = head;
	for(; cur; cur = cur->next)
	{
		free(cur);
	}
	return ;
}
