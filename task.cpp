#include <iostream>

using std::abs;
using std::endl;
using std::cout;

const int ROW = 10;
const int COLUMN = 10;

bool minimum(int matr[ROW][COLUMN], int i, int j)
{
    int val = matr[i][j];

    if (i > 0 && val < matr[i - 1][j]) return false;
    if (j > 0 && val < matr[i][j - 1]) return false;
    if (i < ROW && val < matr[i + 1][j]) return false;
    if (j < COLUMN && val < matr[i][j + 1]) return false;

    return val;
}

void matrix(int matr[ROW][COLUMN])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matr[i][j] = rand() % 100 + 1;
            cout << matr[i][j] << "  ";
        }
        cout << endl;
    }
}

void find_all(int matr[ROW][COLUMN], int* ploc_Min)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (minimum(matr, i, j))
            {
                cout << "String " << i + 1 << " column " << j + 1 << " min = " << matr[i][j] << endl;
                (*ploc_Min)++;
            }
        }
    }
}

void found_sum(int matr[ROW][COLUMN], int* psum)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = i + 1; j < COLUMN; j++)
        {
            *psum += abs(matr[i][j]);
        }
    }
}

int main()
{
    int matr[ROW][COLUMN];

    int loc_Min = 0;
    int sum = 0;

    int *ploc_Min = &loc_Min;
    int *psum = &sum;

    cout << "Matrix: " << endl;
    matrix(matr);

    cout << endl << "Minimum: " << endl;
    find_all(matr, ploc_Min);

    cout << endl << "Found " << *ploc_Min << " minimum" << endl;

    found_sum(matr, psum);
    cout << endl << "The final values of the elements lying above the main diagonals: " << *psum << endl;

    return 0;
}
