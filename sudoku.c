#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sudoku.h"

void initBoard(Cell board[SIZE][SIZE])
{ 
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			board[i][j].num = 0;
			board[i][j].is_locked = 0;
		}
	}

	board[1][3].num = 5;
	board[1][3].is_locked = 1;
	board[5][8].num = 3;
	board[5][8].is_locked = 1;
	board[8][1].num = 6;
	board[8][1].is_locked = 1;
}

void printBoard(Cell board[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j % 3 == 2 && j < 8)
			{
				if (board[i][j].num > 0)
					printf("%d|", board[i][j].num);

				else
					printf(".|");
			}

			else
			{

				if (board[i][j].num > 0)
					printf("%d ", board[i][j].num);

				else
					printf(". ");
			}
 		}

		printf("\n");

		if (i % 3 == 2 && i < 8)
			printf("-----+-----+-----\n");
		
	}
}

int isValidMove(Cell board[SIZE][SIZE], int row, int col, int val)
{
	int resRow, resCol, resBox;

	resRow = isNumInRow(board, row, col, val);
	resCol = isNumInCol(board, row, col, val);
	resBox = isNumInBox(board, row, col, val);

	if (resRow || resCol || resBox)
		return 0;
	else
		return 1;
}

int isNumInRow(Cell board[SIZE][SIZE], int row, int col, int val)
{
	int i;

	for (i = 0; i < SIZE; i++)
	{
		if (board[row][i].num == val)
			return 1;
	}

	return 0;
}

int isNumInCol(Cell board[SIZE][SIZE], int row, int col, int val)
{
	int i;

	for (i = 0; i < SIZE; i++)
	{
		if (board[i][col].num == val)
			return 1;
	}

	return 0;
}

int isNumInBox(Cell board[SIZE][SIZE], int row, int col, int val)
{
	int start_row, start_col, end_row, end_col;
	int i, j;

	start_row = 3 * (row / 3);
	start_col = 3 * (col / 3);

	end_row = start_row + 3;
	end_col = start_col + 3;

	for (i = start_row; i < end_row; i++)
	{
		for (j= start_col; j < end_col; j++)
		{
			if (board[i][j].num == val)
				return 1;
		}
	}

	return 0;
}

int isBoardFull(Cell board[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (board[i][j].num == 0)
				return 0;
		}
	}

	return 1;
}

int userInput(int* row, int* col, int* val)
{
	int inputOk;

	inputOk = scanf("%d %d %d", row, col, val);
	
	if (inputOk != 3)
	{
		while (getchar() != '\n');
		return 0;
	}

	else
	{
		if (*row <= 9 && *row >= 1 && *col <= 9 && *col >= 1 && *val <= 9 && *val >= 1)
		{
			*row = *row - 1;
			*col = *col - 1;
			return 1;
		}
		else
			return 0;
	}
}