#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("**************************\n");
	printf("******    1.play    ******\n");
	printf("******    0.exit    ******\n");
	printf("**************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	int n = 0;
	do
	{
		menu();
		printf("�뿪ʼ��Ϸ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
