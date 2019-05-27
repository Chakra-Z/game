#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	int input = 0;
	char ret = 0;
	char board[ROW][COL] = { 0 };//row,col�ֱ�������̵��к���
	InitBoard(board, ROW, COL);//��ʼ������
	printf("��ѡ��������߻���������ߣ�1.�������� 2.�������\n");
	scanf("%d", &input);
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)
	{
		if (input == 1)//��������
		{
			ComputerMove(board, ROW, COL);
			ret = IsWin(board, ROW, COL);//�ж���Ӯ
			if (ret != ' ')
			{
				break;
			}
			DisplayBoard(board, ROW, COL);
			PlayerMove(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != ' ')//���Ի����Ӯ����Ϸ��ƽ�֣���Ϸ����
			{
				break;
			}
			DisplayBoard(board, ROW, COL);
		}
		if (input == 2)//�������
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
	//���Ӯ--����'x'
	//����Ӯ--����'0'
	//ƽ��----����'P'
	//����----����' '
	if (ret == 'P')
	{
		printf("ƽ��\n");
	}
	else if (ret == 'x')
	{
		printf("���Ӯ\n");
	}
	else if (ret == 'o')
	{
		printf("����Ӯ\n");
	}
	DisplayBoard(board, ROW, COL);
}

void InitBoard(char board[ROW][COL], int row, int col)//��ʼ������
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

void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����
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
				if (j < col - 1)//���һ�в���ӡ|
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)//������
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
	while (1)
	{
		x = rand() % row;//��������������rowΪ3�������0-2֮��������
		y = rand() % col;
		if (board[x][y] == ' ')//�����⵽���λ��Ϊ�ո񣬵������壬���ո��Ϊ��o��
		{
			board[x][y] = 'o';
			break;//��������߳ɹ���ͣ��
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)//�����
{
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//ҪΪ�������ʱ���ǣ��±�Ҫ��1��ʼ
		{
			if (board[x - 1][y - 1] == ' ')//ע�������һ��������λ���ǿո�������壬���ո��Ϊ��x��
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else//�������Ϸ������λ�ò��ǿո���ʾ�����ѱ�ռ��
			{
				printf("�������Ѿ���ռ��\n");
			}
		}
		else//��������겻�ڸ�����Χ�ڼ�Ϊ�Ƿ�����
		{
			printf("������Ƿ�\n");
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)//�ж�ƽ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)//������ȫ������һ�����������пո񣬷���0
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;//û�м����ո�˵�������Ѿ�����������Ϊƽ�֣�����1
}

char IsWin(char board[ROW][COL], int row, int col)//�ж���Ӯ
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	//��Ϸ��Ӯ
	for (i = 0; i < row; i++)//������
	{
		tmp = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')//�ж������ַ���ȵ�����Ϊ�ո�
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
	for (j = 0; j < col; j++)//������
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
	for (i = 0, j = 0; i < row - 1, j < col - 1; i++, j++)//���ϵ�����
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

	for (i = 0, j = row - 1; i < row - 1, j>0; i++, j--)//���ϵ�����
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

	//�ж�ƽ��
	if (IsFull(board, row, col))
	{
		return 'P';
	}
	//��Ϸ����
	return ' ';
}