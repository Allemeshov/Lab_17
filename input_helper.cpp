#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "input_helper.h"
using namespace std;

void Welcome()
{
    cout << "Hello! this is lab 15 of Alexander Lemeshov.\n\n";
}

int selectInputType()
{
    int result = -1;
    while (result < 0 || 4 < result)
    {
        cout << "Please, choose among 4 types of input:\n";
        cout << "\t1 - Console type\n";
        cout << "\t2 - From file type\n";
        cout << "\t3 - Random number from range type\n";
        cout << "\t4 - Calculated by formula type\n";
        cout << "\t0 - Quit application\n";
        cout << "Type: ";
        cin >> result;
    }
    return result;
}
int selectOutputType()
{
    int result = -1;
    while (result < 1 || 2 < result)
    {
        cout << "Please, choose among 4 types of input:\n";
        cout << "\t1 - Console type\n";
        cout << "\t2 - To file type\n";
        cout << "Type: ";
        cin >> result;
    }
    return result;
}

int inputSizeConsole()
{
    int size = 0;
    while (size < 2 || 100 < size)
    {
        cout << "\nPlease, enter matrix size (width = height < 100): ";
        cin >> size;
    }
    return size;
}
void inputMatrixConsole(int matrix[][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Please, enter matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << "\n\n";
}

int inputDataFromFile(int matrix[][100], string path)
{
    ifstream file;
    file.open(path);
    int size;
    if (file.good())
    {
        // string temp;
        // getline(file, temp);
        file >> size;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                file >> matrix[i][j];
            }
        }
        cout << "\nData was successfully read!\n";
    }
    else
        size = -1;
    file.close();

    return size;
}

int inputSizeRandom()
{
    return rand() % 9 + 2;
}
void inputMatrixRandom(int matrix[][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 201 - 100;
        }
    }
}

void inputMatrixFormula(double matrix[][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = (i <= j) ? (1.0 / (i * i + 2.0)) : (1.0 / (i + j + 1.0));
        }
    }
}
