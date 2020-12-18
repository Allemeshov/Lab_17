#pragma once
#include <iostream>
#include <fstream>
#include "output_helper.h"
using namespace std;

void outputMatrixConsole(int matrix[][100], int width, int height)
{
    cout << "\n\n";
    cout << "\nWork is done! Your new matrix: \n";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "matrix[" << i << "][" << j << "]: ";
            cout << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
void outputMatrixConsole(double matrix[][100], int width, int height)
{
    cout << "\n\n";
    cout << "\nWork is done! Your new matrix: \n";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "matrix[" << i << "][" << j << "]: ";
            cout << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
void outputMatrixFile(int matrix[][100], int width, int height, string path)
{
    fstream file;
    file.open(path, fstream::out | fstream::trunc);
    if (file.good())
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                file << matrix[i][j] << "   ";
            }
            file << endl;
        }
        cout << "\nFile was successfully written!\n";
    }
    else
        cout << "\nCanno write file!\n";
    file.close();
}
void outputMatrixFile(double matrix[][100], int width, int height, string path)
{
    ifstream file;
    file.open(path);
    if (file.good())
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << matrix[i][j] << "   ";
            }
            cout << "\n";
        }
    }
    else
        cout << "\nCanno write file!\n";
    file.close();
}