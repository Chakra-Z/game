#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COUNT 10
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
void SetMine(char arr[ROWS][COLS], int row, int col);
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
void SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);
int IsWin(char show[ROWS][COLS], int row, int col);