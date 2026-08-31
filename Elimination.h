#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Elimination{

public: 
    static vector<double> solve(double **triSup, vector<double> &vars, double *B, const int NUM);

private:
    static void pivotParcial(double **A,double *B, int k, const int NUM);
    static void triangularSuperior(double **A, double *B, const int NUM);
    static void subsRegressiva(double **triSup, vector<double> &vars, double *B, const int NUM);
};