#pragma once
#include"stdlib.h"

void FillRand(double arr[], const int n);
void FillRand(double** arr, const int m, const int n);
template<typename T>void FillRand(T arr[], const int n);
template<typename T>void FillRand(T** arr, const int m, const int n);
