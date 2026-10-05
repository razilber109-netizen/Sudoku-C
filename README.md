# 🧩 C Terminal Sudoku

A fully functional, interactive Sudoku game built in C, designed to run directly in the terminal. 
This project was developed to demonstrate clean code principles, robust user input handling, and algorithmic board generation.

## ✨ Features
* **Dynamic Board Generation:** Uses a valid base grid combined with a band-row shuffling algorithm to ensure a unique, playable board every game.
* **Difficulty Levels:** Choose between Easy, Medium, and Hard (dynamically adjusts the number of hidden cells).
* **Robust Input Validation:** 
  * Enforces standard Sudoku rules (checks rows, columns, and 3x3 sub-grids).
  * Safely handles invalid user inputs (e.g., entering letters instead of numbers) using active buffer clearing.
* **Modular Design:** Clear separation between the main game loop, core game logic, and data structures.

## 🎮 How to Play
1. Run the game in your terminal.
2. Select your preferred difficulty level (1-3).
3. Enter your moves using the format: `Row Column Number` (e.g., `3 3 6`).
4. Fill the entire board without breaking Sudoku rules to win!

## 🛠️ Compilation and Execution
To compile and run the game on your local machine, use a standard C compiler like `gcc`:

```bash
gcc main.c sudoku.c -o sudoku
./sudoku
```

## 📁 Project Structure
* `main.c` - Manages the game loop, difficulty selection menu, and user interface.
* `sudoku.c` - Contains the core game mechanics, random board shuffling, and rule validation algorithms.
* `sudoku.h` - Header file containing the `Cell` struct definition and function prototypes.
