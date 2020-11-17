#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

vector<vector<char>> res;
void print(vector<vector<char>> board);
bool feasible(vector<vector<char>> board, int x, int y, int k);
void sudoku(vector<vector<char>> &board, int x, int y);
void solveSudoku(vector<vector<char>> &board);

void printExecutionTime(ClockTime start_time, ClockTime end_time)
{
    auto execution_time_ns = duration_cast<nanoseconds>(end_time - start_time).count();
    auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
    auto execution_time_sec = duration_cast<seconds>(end_time - start_time).count();
    auto execution_time_min = duration_cast<minutes>(end_time - start_time).count();
    auto execution_time_hour = duration_cast<hours>(end_time - start_time).count();

    cout << "\nExecution Time: ";
    if (execution_time_hour > 0)
        cout << "" << execution_time_hour << " Hours, ";
    if (execution_time_min > 0)
        cout << "" << execution_time_min % 60 << " Minutes, ";
    if (execution_time_sec > 0)
        cout << "" << execution_time_sec % 60 << " Seconds, ";
    if (execution_time_ms > 0)
        cout << "" << execution_time_ms % long(1E+3) << " MicroSeconds, ";
    if (execution_time_ns > 0)
        cout << "" << execution_time_ns % long(1E+6) << " NanoSeconds, ";
}
int main()
{
    ClockTime start_time = Clock::now();
    vector<vector<char>> board = {{'.', '.', '.', '.', '.', '7', '.', '.', '9'}, {'.', '4', '.', '.', '8', '1', '2', '.', '.'}, {'.', '.', '.', '9', '.', '.', '.', '1', '.'}, {'.', '.', '5', '3', '.', '.', '.', '7', '2'}, {'2', '9', '3', '.', '.', '.', '.', '5', '.'}, {'.', '.', '.', '.', '.', '5', '3', '.', '.'}, {'8', '.', '.', '.', '2', '3', '.', '.', '.'}, {'7', '.', '.', '.', '5', '.', '.', '4', '.'}, {'5', '3', '1', '.', '7', '.', '.', '.', '.'}};
    solveSudoku(board);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    ClockTime end_time = Clock::now();
    printExecutionTime(start_time, end_time);
}
void print(vector<vector<char>> board)
{
    res = board;
}
bool feasible(vector<vector<char>> board, int x, int y, int k)
{
    char kk = k + 48;
    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == kk || board[x][i] == kk)
            return false;
    }
    int a = x / 3, b = y / 3;
    for (int i = 3 * a; i < 3 * a + 3; i++)
    {
        for (int j = 3 * b; j < 3 * b + 3; j++)
        {
            if (board[i][j] == kk)
                return false;
        }
    }
    return true;
}
void sudoku(vector<vector<char>> &board, int x, int y)
{

    if (y == 9)
    {
        if (x == 8)
        {
            //print(board);
            res = board;
            return;
        }
        else
            sudoku(board, x + 1, 0);
    }
    else
    {
        if (board[x][y] == '.')
        {
            for (int k = 1; k < 10; k++)
            {
                if (feasible(board, x, y, k))
                {
                    char kk = k + 48;
                    board[x][y] = kk;
                    sudoku(board, x, y + 1);
                    board[x][y] = '.';
                }
            }
        }
        else
        {
            sudoku(board, x, y + 1);
        }
    }
}
void solveSudoku(vector<vector<char>> &board)
{
    sudoku(board, 0, 0);
    board.clear();
    board = res;
    return;
}
