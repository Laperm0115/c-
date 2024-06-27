#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sys.h"

#define MS_100 1000*1000
#define NAME_LEN 3
#define NUMBER_LEN 13

int main(int argc, char* argv)
{
	char cmd[4] = "";
	char buf[32] = "";
	char *line = "-----------------------------\n";
	int command = 0;
	system("clear");
	printf("%s",line);
	printf("%s","전화번호 관리프로그램 시작...\n");
	printf("%s","저장된 전화 번호 불러오기 (Yes/NO) \n");
	fgets(cmd,sizeof(cmd),stdin);
	if(strcmp(cmd,"yes") == 0 || strcmp(cmd,"Yes") == 0)
	{
		printf("%s","파일을 불러오는중입니다...\n");
		File_store();
	}
	else
		printf("%s","파일을 불러오지 않습니다!!\n");

	while(1)
	{
		memset(buf,0,sizeof(buf));
		usleep(MS_100);
		printf("%s",line);
		printf("선택할 기능을 고르시오.\n");
		printf("a: 전화번호 입력\n");
		printf("b: 전화번호 삭제 ex) b 010-1234-1234\n");
		printf("c: 전화번호 출력\n");
		printf("d: 전화번호 검색 ex) d minsu\n");
		printf("e: 화면 클리어 \n");
		printf("f: 전화번호 저장파일 삭제 \n");
		printf("t: 테스트 프로그램 실행 \n");
		printf("q: 프로그램 종료\n");
		printf("%s",line);
		scanf("%s",cmd);
		getchar();
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
					scanf("%s",buf);
					if(strlen(buf) < NUMBER_LEN)
					{
						printf("[ERROR] 올바른 형식이아닙니다..\n");
						break;
					}
					Linked_list_remove(buf);
					break;
				}
			case 'c':
				{
					print_data();
					break;
				}
			case 'd':
				{
					scanf("%s",buf);
					if(strlen(buf) < NAME_LEN)
					{
						printf("[ERROR] 올바른 형식이아닙니다..\n");
						break;
					}
					Linked_list_search(buf);
					break;
				}
			case 'e':
				{
					system("clear");
					break;
				}
			case 'f':
				{
					File_remove();
					break;
				}
			case 't':
				{
					Test_Insert_pn_info();
					break;
				}
			case 'q':
				goto exit;
			default:
				{
					printf("[ERROR] 그런 기능은 존재하지않습니다!\n");
					break;
				}
		}
	}
exit:
	Linkd_list_init();
	fprintf(stdout,"시스템을 종료합니다...\n");
	return 0;
}
