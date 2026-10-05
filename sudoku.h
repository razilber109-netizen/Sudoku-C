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
    int isValidMove(Cell board[SIZE][SIZE], int row, int col, int val);
    int isNumInRow(Cell board[SIZE][SIZE], int row, int col, int val);
    int isNumInCol(Cell board[SIZE][SIZE], int row, int col, int val);
    int isNumInBox(Cell board[SIZE][SIZE], int row, int col, int val);
    int isBoardFull(Cell board[SIZE][SIZE]);
    int userInput(int* row, int* col, int* val);

#endif
