/*
    13.	Подсчитать, сколько отрицательных элементов в каждой отдельно взятой строке матрицы. Удалить строку, в которой отрицательных элементов больше всего. Поменять местами главную и побочную диагонали
*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "input_helper.h"
#include "matrix_worker.h"
#include "output_helper.h"

using namespace std;

void console()
{
    int size = inputSizeConsole();

    int matrix[100][100];

    inputMatrixConsole(matrix, size);

    outputMatrixConsole(matrix, size, size);

    processMatrix(matrix, size);
}
void fromFile()
{
    cout << "Please, enter path to file: ";
    string path;
    // getline(cin, path);
    cin >> path;

    int matrix[100][100];

    int size = inputDataFromFile(matrix, path);

    if (size != -1)
    {

        outputMatrixConsole(matrix, size, size);

        processMatrix(matrix, size);
    }
    else
        cout << "Cannot read file";
}
void random()
{
    srand(time(NULL));
    int size = inputSizeRandom();

    int matrix[100][100];

    inputMatrixRandom(matrix, size);

    outputMatrixConsole(matrix, size, size);

    processMatrix(matrix, size);
}
void formula()
{
    int size = inputSizeConsole();

    double matrix[100][100];

    inputMatrixFormula(matrix, size);

    outputMatrixConsole(matrix, size, size);

    processMatrix(matrix, size);
}
int main()
{
    Welcome();

    bool toQuit = false;

    while (!toQuit)
    {
        int selection = selectInputType();

        switch (selection)
        {
        case 1:
            console();
            break;

        case 2:
            fromFile();
            break;

        case 3:
            random();
            break;

        case 4:
            formula();
            break;
        default:
        {
            toQuit = true;
            cout << "\n\nIt's very sad to see you going. Anyway, have a nice day!\n";
            break;
        }
        }
    }
    system("pause");
    return 1;
}