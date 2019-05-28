#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');//初始化设计者的棋盘
	InitBoard(show, ROWS, COLS, '*');//初始化玩家的棋盘
	SetMine(mine, ROW, COL);//布雷
	DisplayBoard(mine, ROW, COL);//打印设计者的棋盘
	DisplayBoard(show, ROW, COL);//打印玩家的棋盘
	SafeMine(mine, show, ROW, COL);//第一次不炸死
	FindMine(mine, show, ROW, COL);//排雷

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}