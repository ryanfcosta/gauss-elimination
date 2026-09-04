#pragma once

#include <cmath>
#include <iostream>
#include <vector>
using namespace std; 

class GJacobi{
public:
    static void solve(double**A, vector<double> & vars, double *B, const int  NUM);
private:
    static bool critLinhas(double** A, const int NUM);
    static void gaussJacobi(double** A, vector <double> &vars, double* B, const int NUM);
};