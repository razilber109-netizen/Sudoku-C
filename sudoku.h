#ifndef SUDOKU_H
    #define SUDOKU_H

    #define SIZE 9

    typedef struct
    {
	    unsigned char num;
	    unsigned char is_locked;
    }Cell;

    void initBoard(Cell board[SIZE][SIZE]);

    void printBoard(Cell board[SIZE][SIZE]);

    /*
     * Checks if placing 'val' at the specified 'row' and 'col'
     * is valid according to Sudoku rules (row, column, and 3x3 grid).
     */
    int isValidMove(Cell board[SIZE][SIZE], int row, int col, int val);

    int isNumInRow(Cell board[SIZE][SIZE], int row, int col, int val);

    int isNumInCol(Cell board[SIZE][SIZE], int row, int col, int val);

    int isNumInBox(Cell board[SIZE][SIZE], int row, int col, int val);

    int isBoardFull(Cell board[SIZE][SIZE]);

    /*
     * Handles user input for row, column, and value.
     * Returns 1 if input is valid and within 1-9 bounds, 0 otherwise.
     */
    int userInput(int* row, int* col, int* val);


#endif
