#pragma once
#include <string>

void Welcome();
int selectInputType();
int selectOutputType();
int inputSizeConsole();
void inputMatrixConsole(int matrix[][100], int size);
int inputDataFromFile(int matrix[][100], std::string path);
int inputSizeRandom();
void inputMatrixRandom(int matrix[][100], int size);
void inputMatrixFormula(double matrix[][100], int size);