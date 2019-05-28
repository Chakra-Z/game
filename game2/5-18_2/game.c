#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void SetMine(char arr[ROWS][COLS], int row, int col)//布雷
{
	int x = 0;
	int y = 0;
	int count = COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)//打印行号和列号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//打印九乘九的棋盘
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入要排查的坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标的有效性
		{
			if (mine[x][y] == '1')//判断是否为雷，如果是雷提示被炸死并打印设计者棋盘
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//如果不是雷，获取周围雷的个数并展开
			{
				int c = GetMineCount(mine, x, y);
				show[x][y] = c + '0';
				OpenMine(mine, show, row, col, x, y);
				DisplayBoard(show, row, col);
				if (IsWin(show, row, col) == COUNT)
				{
					break;
				}
			}
		}
		else//如果坐标无意义，提示坐标非法
		{
			printf("坐标非法\n");
		}
	}
	if (IsWin(show, row, col) == COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}

void SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret = 1;
	int ch = 0;
	printf("请输入要排查的坐标：>");
	scanf("%d%d", &x, &y);
	if (mine[x][y] == '1')//如果第一次输入坐标为雷将坐标改为0即非雷
	{
		mine[x][y] = '0';//获取周围雷的个数
		ch = GetMineCount(mine, x, y);
		show[x][y] = ch + '0';////数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII
		while (ret)//在其余有空的地方设置一个雷
		{
			x = rand() % 9 + 1;//生成随机数1-9
			y = rand() % 9 + 1;
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
			}
			ret--;
		}
	}
	OpenMine(mine, show, row, col, x, y);
	DisplayBoard(show, row, col);
}

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int ret = 0;
	ret = GetMineCount(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x - 1 > 0 && y > 0 && show[x - 1][y] == '*')
			OpenMine(mine, show, row, col, x - 1, y);

		if (x - 1 > 0 && y + 1 <= col && show[x - 1][y + 1] == '*')
			OpenMine(mine, show, row, col, x - 1, y + 1);

		if (x > 0 && y + 1 <= col && show[x][y + 1] == '*')
			OpenMine(mine, show, row, col, x, y + 1);

		if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == '*')
			OpenMine(mine, show, row, col, x + 1, y + 1);

		if (x + 1 <= row && y > 0 && show[x + 1][y] == '*')
			OpenMine(mine, show, row, col, x + 1, y);

		if (x + 1 <= row && y - 1 > 0 && show[x + 1][y - 1] == '*')
			OpenMine(mine, show, row, col, x + 1, y - 1);

		if (x > 0 && y - 1 > 0 && show[x][y - 1] == '*')
			OpenMine(mine, show, row, col, x, y - 1);

		if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == '*')
			OpenMine(mine, show, row, col, x - 1, y - 1);

	}
	else
	{
		show[x][y] = GetMineCount(mine, x, y) + '0';
	}
}

int IsWin(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
