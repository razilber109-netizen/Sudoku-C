#include <stdio.h>
#include "sudoku.h"

int main()
{
	Cell board[SIZE][SIZE];
	initBoard(board);

	while (!isBoardFull(board))
	{
		int row, col, val;
		int resInput ;

		printBoard(board);

		printf("please enter row, colmn, number in that way: \n");

		resInput = userInput(&row, &col, &val);

		if (resInput)
		{
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