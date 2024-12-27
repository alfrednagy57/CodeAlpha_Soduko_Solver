# Sudoku Solver

This project is a simple Sudoku solver implemented in C++. The program allows users to input a Sudoku puzzle and solves it using a backtracking algorithm. It also includes functionality to validate and display the Sudoku grid.

## Features
- **User-Friendly Input**: Input the Sudoku puzzle slot by slot, with the ability to correct mistakes.
- **Grid Validation**: Ensures the entered numbers are valid for the Sudoku rules.
- **Backtracking Algorithm**: Solves the puzzle efficiently.
- **Formatted Output**: Displays the Sudoku grid in a clear and readable format.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC, Clang).
- Basic understanding of compiling and running C++ programs.

### Compilation
To compile the program, use a command like the following:
```bash
 g++ -o sudoku_solver sudoku_solver.cpp
```

### Running the Program
Run the compiled executable:
```bash
./sudoku_solver
```

## How to Use
1. **Enter the Sudoku Grid**:
   - The program will prompt you to input numbers row by row.
   - Use `0` for empty cells.
   - If a mistake is made, input `10` to re-enter the last number.
2. **Submit or Re-enter**:
   - After entering the grid, you can confirm or choose to re-enter.
3. **View the Solution**:
   - The program will solve the Sudoku puzzle and display the solved grid.
   - If no solution exists, you will be informed.

## Code Overview
### Key Functions
- `void printGrid(int grid[N][N])`: Displays the Sudoku grid.
- `void entersudo(int grid[N][N])`: Handles user input for the Sudoku puzzle.
- `bool isSafe(int grid[N][N], int row, int col, int num)`: Checks if a number can be placed in a cell.
- `bool solveSudoku(int grid[N][N])`: Uses backtracking to solve the Sudoku puzzle.

### Main Logic
The program initializes an empty Sudoku grid, collects user input, and attempts to solve it using `solveSudoku`. If a solution is found, it displays the solved grid; otherwise, it notifies the user of failure.

## Example
Input:
```
0 0 3 0 0 0 0 2 0
0 5 0 0 0 8 0 0 0
0 0 0 0 0 0 6 0 1
...
```
Output:
```
 ---------------------
| 4 8 3 | 9 2 1 | 6 5 7 |
| 9 6 7 | 3 4 8 | 2 1 5 |
| 2 5 1 | 7 6 5 | 8 9 3 |
 ---------------------
...
```

## Contributing
Contributions are welcome! Feel free to submit issues or pull requests.

---

Thank you for checking out this Sudoku solver! Happy solving!

