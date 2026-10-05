#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include "sudoku.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	Cell board[SIZE][SIZE];
	int difficulty;
	int cellsToHide = 0;

	srand(time(NULL));

	printf("Welcome to Sudoku!\n");
	printf("Choose difficulty level:\n");
	printf("1. Easy\n");
	printf("2. Medium\n");
	printf("3. Hard\n");

	while (cellsToHide == 0)
	{
		printf("Enter your choice (1-3): ");
		if (scanf("%d", &difficulty) != 1)
		{
			while (getchar() != '\n'); 
			printf("Invalid input. ");
			continue;
		}

		if (difficulty == 1) cellsToHide = 30;
		else if (difficulty == 2) cellsToHide = 45;
		else if (difficulty == 3) cellsToHide = 55;
		else printf("Please enter a number between 1 and 3.\n");
	}
	initBoard(board, cellsToHide);

	// Main game loop - runs until the board is completely filled
	while (!isBoardFull(board))
	{
		int row, col, val;
		int resInput;

		printBoard(board);

		// 1. Get and validate raw input format
		printf("Please enter row, column, and number (e.g., 3 3 6): \n");
		resInput = userInput(&row, &col, &val);

		if (resInput)
		{
			// 2. Check game rules and cell availability
			if (!board[row][col].is_locked)
			{
				if (isValidMove(board, row, col, val))
					board[row][col].num = val;
				else
					printf("invalid move \n");
			}

			else
				printf("This cell is locked \n");
		}

		else
			printf("invalid input \n");
	}
	printBoard(board);
	printf("You Won!\n");

	return 0;
}