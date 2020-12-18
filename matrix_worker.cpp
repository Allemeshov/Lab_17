#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "input_helper.h"
#include "output_helper.h"
using namespace std;

int findRowIdToDelete(int matrix[][100], int size)
{
    int negatives = 0, maxNegatives = -1, rowIdToDelete = -1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] < 0)
                negatives++;
        }
        if (negatives > maxNegatives)
        {
            maxNegatives = negatives;
            rowIdToDelete = i;
        }
        negatives = 0;
    }
    return rowIdToDelete;
}
int deleteRowOnId(int matrix[][100], int size, int rowIdToDelete)
{
    if (rowIdToDelete != -1)
    {
        if (rowIdToDelete != size - 1)
        {
            for (int i = 0; i < size; i++)
            {
                matrix[rowIdToDelete][i] = matrix[rowIdToDelete + 1][i];
            }
        }
        size--;
    }
    return size;
}
int findRowIdToDelete(double matrix[][100], int size)
{
    int negatives = 0, maxNegatives = 0, rowIdToDelete = -1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] < 0)
                negatives++;
        }
        if (negatives > maxNegatives)
        {
            maxNegatives = negatives;
            rowIdToDelete = i;
        }
        negatives = 0;
    }
    return rowIdToDelete;
}
int deleteRowOnId(double matrix[][100], int size, int rowIdToDelete)
{
    if (rowIdToDelete != -1)
    {
        if (rowIdToDelete != size - 1)
        {
            for (int i = 0; i < size; i++)
            {
                matrix[rowIdToDelete][i] = matrix[rowIdToDelete + 1][i];
            }
        }
        size--;
    }
    return size;
}

void swapDiagonals(int matrix[][100], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        temp = matrix[i][i];
        matrix[i][i] = matrix[size - 1 - i][i];
        matrix[size - 1 - i][i] = temp;
    }
    outputMatrixConsole(matrix, size, size);
}
void processMatrix(int matrix[][100], int size)
{

    int rowIdToDelete = -1;

    swapDiagonals(matrix, size);

    rowIdToDelete = findRowIdToDelete(matrix, size);

    size = deleteRowOnId(matrix, size, rowIdToDelete);

    int outputType = selectOutputType();

    switch (outputType)
    {
    case 1:
        outputMatrixConsole(matrix, size + 1, size);
        break;
    case 2:
    {
        string path;
        cout << "\nPlease, enter path: ";
        // getline(cin, path);
        cin >> path;
        outputMatrixFile(matrix, size + 1, size, path);
        break;
    }
    default:
        break;
    }
}
void swapDiagonals(double matrix[][100], int size)
{
    double temp;
    for (int i = 0; i < size; i++)
    {
        temp = matrix[i][i];
        matrix[i][i] = matrix[size - 1 - i][i];
        matrix[size - 1 - i][i] = temp;
    }
    outputMatrixConsole(matrix, size, size);
}
void processMatrix(double matrix[][100], int size)
{

    int rowIdToDelete = -1;

    swapDiagonals(matrix, size);

    rowIdToDelete = findRowIdToDelete(matrix, size);

    if (rowIdToDelete != -1)
    {
        size = deleteRowOnId(matrix, size, rowIdToDelete);
        outputMatrixConsole(matrix, size + 1, size);
    }
    else
        cout << "\nImpossible to delete a row, because there's no negetive elements!\n\n\n";
}
