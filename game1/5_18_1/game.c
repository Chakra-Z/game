#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	int input = 0;
	char ret = 0;
	char board[ROW][COL] = { 0 };//row,col分别代表棋盘的行和列
	InitBoard(board, ROW, COL);//初始化棋盘
	printf("请选择电脑先走还是玩家先走：1.电脑先走 2.玩家先走\n");
	scanf("%d", &input);
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)
	{
		if (input == 1)//电脑先走
		{
			ComputerMove(board, ROW, COL);
			ret = IsWin(board, ROW, COL);//判断输赢
			if (ret != ' ')
			{
				break;
			}
			DisplayBoard(board, ROW, COL);
			PlayerMove(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != ' ')//电脑或玩家赢得游戏或平局，游戏结束
			{
				break;
			}
			DisplayBoard(board, ROW, COL);
		}
		if (input == 2)//玩家先走
		{
			{

				PlayerMove(board, ROW, COL);
				ret = IsWin(board, ROW, COL);
				if (ret != ' ')
				{
					break;
				}
				DisplayBoard(board, ROW, COL);
				ComputerMove(board, ROW, COL);
				ret = IsWin(board, ROW, COL);
				if (ret != ' ')
				{
					break;
				}
				DisplayBoard(board, ROW, COL);
			}
		}
	}
	//玩家赢--返回'x'
	//电脑赢--返回'0'
	//平局----返回'P'
	//继续----返回' '
	if (ret == 'P')
	{
		printf("平局\n");
	}
	else if (ret == 'x')
	{
		printf("玩家赢\n");
	}
	else if (ret == 'o')
	{
		printf("电脑赢\n");
	}
	DisplayBoard(board, ROW, COL);
}

void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}

		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//最后一列不打印|
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)//电脑走
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % row;//产生随机数，如果row为3，则产生0-2之间的随机数
		y = rand() % col;
		if (board[x][y] == ' ')//如果检测到这个位置为空格，电脑下棋，将空格改为‘o’
		{
			board[x][y] = 'o';
			break;//如果电脑走成功就停下
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)//玩家走
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//要为玩家输入时考虑，下标要从1开始
		{
			if (board[x - 1][y - 1] == ' ')//注意坐标减一，如果这个位置是空格，玩家下棋，将空格改为‘x’
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else//如果坐标合法但这个位置不是空格，提示坐标已被占用
			{
				printf("该坐标已经被占用\n");
			}
		}
		else//输入的坐标不在给定范围内即为非法坐标
		{
			printf("该坐标非法\n");
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)//判断平局
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)//把棋盘全部遍历一遍后如果检测出有空格，返回0
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;//没有检测出空格，说明棋盘已经被填满，即为平局，返回1
}

char IsWin(char board[ROW][COL], int row, int col)//判断输赢
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	//游戏输赢
	for (i = 0; i < row; i++)//横三行
	{
		tmp = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')//判断三个字符相等但不能为空格
			{
				;
			}
			else
			{
				tmp = 1;
				break;
			}
		}
		if (tmp == 0)
		{
			return board[i][j];
		}

	}
	for (j = 0; j < col; j++)//竖三行
	{
		tmp = 0;
		for (i = 0; i < row - 1; i++)
		{
			if (board[i][j] == board[i + 1][j] && board[i][j] != 0)
			{
				;
			}
			else
			{
				tmp = 1;
				break;
			}
		}
		if (tmp == 0)
		{
			return board[i][j];
		}

	}
	for (i = 0, j = 0; i < row - 1, j < col - 1; i++, j++)//左上到右下
	{
		tmp = 0;
		if ((tmp == 0) && (board[i][j] == board[i + 1][j + 1]) && board[i][j] != ' ')
		{
			;
		}
		else
		{
			tmp = 1;
			break;
		}
	}
	if (tmp == 0)
	{
		return board[i][j];
	}

	for (i = 0, j = row - 1; i < row - 1, j>0; i++, j--)//右上到左下
	{
		tmp = 0;
		if (board[i][j] == board[i + 1][j - 1])
		{
			;
		}
		else
		{
			tmp = 1;
			break;
		}
	}
	if (tmp == 0)
	{
		return board[i][j];
	}

	//判断平局
	if (IsFull(board, row, col))
	{
		return 'P';
	}
	//游戏继续
	return ' ';
}