#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sys.h"

#define MS_100 1000*1000
int main(int argc, char* argv)
{
	char cmd[4] = "";
	int command = 0;
	fprintf(stdout,"전화번호 관리프로그램 시작...\n");
	fprintf(stdout,"저장된 전화 번호 불러오기 (Yes/NO) \n");
	fgets(cmd,sizeof(cmd),stdin);
	if(strcmp(cmd,"yes") == 0 || strcmp(cmd,"Yes") == 0)
	{
		fprintf(stdout,"save file!!\n");
		// save file func
	}
	while(1)
	{
		usleep(MS_100);
		printf("선택할 기능을 고르시오.\n");
		printf("a: 전화번호 입력\n");
		printf("b: 전화번호 삭제 ex) b 010-1234-1234\n");
		printf("c: 전화번호 출력\n");
		printf("d: 전화번호 검색 ex) d minsu\n");
		printf("q: 프로그램 종료\n");
		fgets(cmd,sizeof(cmd),stdin);
		command = (int)cmd[0];
		switch(command)
		{
			case 'a':
				{
					Insert_pn_info();
					break;
				}
			case 'b':
				{
					Linked_list_remove("010-1234-1234");
					break;
				}
			case 'c':
				{
					print_data();
					break;
				}
			case 'd':
				{
					Linked_list_search("minsu");
					break;
				}
			case 'q':
				goto exit;
			default:
				{
					printf("그런 기능은 존재하지않습니다!\n");
					break;
				}
		}
	}
exit:
	Linkd_list_init();
	fprintf(stdout,"시스템을 종료합니다...\n");
	return 0;
}
