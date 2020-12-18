#pragma once
#include <string>

void outputMatrixConsole(int matrix[][100], int width, int height);
void outputMatrixConsole(double matrix[][100], int width, int height);
void outputMatrixFile(int matrix[][100], int width, int height, std::string path);
void outputMatrixFile(double matrix[][100], int width, int height, std::string path);
