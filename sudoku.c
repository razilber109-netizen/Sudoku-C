#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sudoku.h"

void initBoard(Cell board[SIZE][SIZE])
{ 
	int i, j;
	int baseGrid[SIZE][SIZE] = {
	{5, 3, 4, 6, 7, 8, 9, 1, 2},
	{6, 7, 2, 1, 9, 5, 3, 4, 8},
	{1, 9, 8, 3, 4, 2, 5, 6, 7},
	{8, 5, 9, 7, 6, 1, 4, 2, 3},
	{4, 2, 6, 8, 5, 3, 7, 9, 1},
	{7, 1, 3, 9, 2, 4, 8, 5, 6},
	{9, 6, 1, 5, 3, 7, 2, 8, 4},
	{2, 8, 7, 4, 1, 9, 6, 3, 5},
	{3, 4, 5, 2, 8, 6, 1, 7, 9}
	};

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (rand() % 2 == 1)
			{
				board[i][j].num = baseGrid[i][j]; 
				board[i][j].is_locked = 1;         
			}
			else
			{
				board[i][j].num = 0;              
				board[i][j].is_locked = 0;        
			}
		}
	}
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
		// Clear the input buffer to prevent infinite loops when a user enters characters instead of numbers
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