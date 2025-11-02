#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <climits> 

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);

bool RowContainsZero(int* row, const int colCount);
int CountRowsWithoutZero(int** a, const int rowCount, const int colCount);

int CountElementOccurrences(int** a, const int rowCount, const int colCount, int element);
bool FindMaxRepeatedElement(int** a, const int rowCount, const int colCount, int& maxRepeated);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 20;

    int rowCount, colCount;
    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);

    Print(a, rowCount, colCount);

    int count = CountRowsWithoutZero(a, rowCount, colCount);
    cout << "1. Number of rows without zero elements: " << count << endl;

    int maxRepeated = 0;
    bool foundRepeated = FindMaxRepeatedElement(a, rowCount, colCount, maxRepeated);

    cout << "\n2. Maximum number that appears more than once:" << endl;
    if (foundRepeated)
        cout << "Found: " << maxRepeated << endl;
    else
        cout << "No number that repeats more than once was found." << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool RowContainsZero(int* row, const int colCount)
{
    for (int j = 0; j < colCount; ++j) {
        if (row[j] == 0) {
            return true;
        }
    }
    return false;
}

int CountRowsWithoutZero(int** a, const int rowCount, const int colCount)
{
    int count = 0;
    for (int i = 0; i < rowCount; ++i) {
        if (!RowContainsZero(a[i], colCount)) {
            count++;
        }
    }
    return count;
}

int CountElementOccurrences(int** a, const int rowCount, const int colCount, int element)
{
    int count = 0;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            if (a[i][j] == element) {
                count++;
            }
        }
    }
    return count;
}

bool FindMaxRepeatedElement(int** a, const int rowCount, const int colCount, int& maxRepeated)
{
    int overallMax = INT_MIN;
    bool foundAny = false;

    bool** checked = new bool* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        checked[i] = new bool[colCount];
        for (int j = 0; j < colCount; j++) {
            checked[i][j] = false;
        }
    }

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            if (!checked[i][j]) {
                int currentElement = a[i][j];

                int count = CountElementOccurrences(a, rowCount, colCount, currentElement);

                if (count > 1) {
                    foundAny = true;
                    if (currentElement > overallMax) {
                        overallMax = currentElement;
                    }
                }

                for (int r = 0; r < rowCount; ++r) {
                    for (int c = 0; c < colCount; ++c) {
                        if (a[r][c] == currentElement) {
                            checked[r][c] = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < rowCount; i++) {
        delete[] checked[i];
    }
    delete[] checked;

    if (foundAny) {
        maxRepeated = overallMax; 
    }

    return foundAny; 
}