#pragma once

#include <cmath>
#include <iostream>
#include <vector>
using namespace std; 

class GJacobi{
public:
    static void solve(double**A, vector<double> & vars, double *B, const int  NUM);
protected:
    static bool critLinhas(double** A, const int NUM);
    static void gaussJacobi(double** A, vector <double> &vars, double* B, const int NUM);
private:
    static bool critParada(vector<double> last, vector<double> current, const int NUM, const double epsilon);
};