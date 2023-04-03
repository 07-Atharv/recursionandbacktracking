// The problem statement states that we have to solve the sudko solver which will be solved in foll ways:-

// First we have to check which is the empty cell in the sudko
// After getting the empty cell we will try the possibilities and for each possibility we will use the recursive call
// We will check the each possible no at the empty cell and we will continue to solve the sudko

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 9
#define M 9
// These function is used to print the solved sudko
void printSudko(int arr[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafeToPlace(int board[N][M], int row, int col, int currvalue)
{
    // 0-9 becaue we have only 9*9 grid means 9 rows and 9 columns so we can assign the default value
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == currvalue)
        {
            // These will check if the current value has duplicate in the entire row
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == currvalue)
        {
            // These will check if the current value has duplicate in the entire column
            return false;
        }
    }

    // Now we have to check if the duplicate of the current index is int the current 3*3 matrix or not if yes then ret false
    int smallmatrrow = row - row % 3;
    int smallmatrcol = col - col % 3;
    // so the evaluation of these is suppose we have blank space at (3,4) and we have to find the starting matrix(3*3) position of these then we have
    // 3-3 % 3 = 3
    // 4-4 % 3 = 3
    // so now we have 3,3 position of the starting matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 0+3 1+3 2+3 = 3 4 5 positions will be checked
            if (board[i + smallmatrrow][j + smallmatrcol] == currvalue)
            {
                return false;
            }
        }
        cout << endl;
    }
}
// Now we have to check the empty places which will help us to fill and solve the sudko
// We will see each step one by one:-
// We have to assign the values in such a way that no value should be repeated in the whole current row
// We have to assign the values in such a way that no value should be repeated in the whole current column
// We have to assign the values in such a way that no value should be repeated in the whole current 3*3 matrix
bool solvePuzzle(int puzzle[N][M], int row, int col)
{
    // Now check the base condtion if pointer is succesfuly reached till the last index then the sudko is successfully solved and we return true
    if (row == N - 1 && col == M - 1)
    {
        return true;
    }
    // Herre we will check column wise if the empty space is there or not if thee is empty space then we have to move to next row and make the col 0 to start again
    if (col == N)
    {
        row++;
        col = 0;
    }
    // Now we have to check if the current position value is empty or not if not then check for the next column
    if (puzzle[row][col] > 0)
    {
        // Here recurion call is occured which wiil call for the next column
        return solvePuzzle(puzzle, row, col + 1);
    }
    for (int x = 1; x <= N; x++)
    {
        // Now we have to check if the given col and row posn is safe to place and we move to next column

        if (isSafeToPlace(puzzle, row, col, x))
        {
            puzzle[row][col] = x;
            // check for next possibiltiy with next column
            if (solvePuzzle(puzzle, row, col + 1))
            {
                return true;
            }
        }
        //These is the backtracking step in which we remove the possible combination number and check for next combination
        puzzle[row][col] = 0;
    }
    return false;
}
int main()
{
    int sudko[N][M] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solvePuzzle(sudko, 0, 0))
    {
        cout << "Solved Puzzle is" << endl;
        printSudko(sudko);
    }
    else
    {
        cout << "No possible combination" << endl;
    }
    return 0;
}