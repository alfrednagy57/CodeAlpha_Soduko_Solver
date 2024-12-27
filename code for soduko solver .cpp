#include <iostream>

const int N = 9;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define speed2  cout.flush();


using namespace std;

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        if (0 == i )
            cout << " ---------------------\n";
        for (int j = 0; j < N; j++) {
            if (0 == j)
                cout << "| ";
            cout << grid[i][j] << " ";
            if (2 == j || 5 == j ||8==j)
                cout << "|";
        }
        if (2 == i || 5 == i || 8 == i)
            cout << "\n ---------------------";
        
        cout << endl;
    }
}
void entersudo(int grid[N][N])
{
    cout << "enter your sudoko game numbers slot by slot: \nenter 0 for empty slots and 10 if you entered a wrong number\n\n\n\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "enter the " << j + 1 << " number in the " << i + 1 << " row " << endl;
            cin >> grid[i][j];
            if (grid[i][j] == 10) {
                if (j > 0)
                {
                    j = j - 2;
                }
                else
                {
                    i--; j = 7;
                }
            }
        }
        cout << "\n\n\n\n";
    }
    cout << "\n\n\n\nyour entered soduko is\n\n\n\n";
    printGrid(grid);
    cout << "enter 1 to submit and 0 to enter the sudo again \n";
    bool ag = false;
    cin >> ag;
    if (!ag)
    {
        entersudo(grid);
    }
}
bool isSafe(int grid[N][N], int row, int col,int num)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == num || grid[row][i] == num) { return false; }
    }

    int SR = row - row % 3;
    int SC = col - col % 3;

    for (int i=SR;i<(3+SR);i++)
    {
        for (int j=SC;j< (3 + SC);j++)
        {
            if (grid[i][j] == num) { return false; }
        }
    }

    return true;
}
bool solveSudoku (int grid[N][N])
{
    bool isEmpty = false; int col = 0, row = 0;

    for (row=0; row < N; row++)
    {
        for (col=0; col < N; col++)
        {
            if (0 == grid[row][col]) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    if (!isEmpty) return true;
    
    for (int x = 1; x <= 9; x++) {
        if (isSafe(grid, row, col, x)) {
            grid[row][col] = x;

            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}


int main()
{
	speed

        int grid[N][N] = {
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    entersudo(grid);
    
    cout << "\n\n\n\n";


    if (solveSudoku(grid)) {
        cout << "Sudoku solved successfully:\n";
        printGrid(grid);
    }
    else {
        cout << "No solution exists for the given Sudoku.\n";
    }

	speed2

	return 0;
}
