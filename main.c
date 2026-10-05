#include <stdio.h>
#include "sudoku.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	Cell board[SIZE][SIZE];

	srand(time(NULL));

	initBoard(board);

	// Main game loop - runs until the board is completely filled
	while (!isBoardFull(board))
	{
		int row, col, val;
		int resInput ;

		printBoard(board);

		// 1. Get and validate raw input format
		printf("please enter row, colmn, number in that way: \n");
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

	printf("You Won!\n");

	return 0;
}