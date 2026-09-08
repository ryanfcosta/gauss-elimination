#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Elimination{

public: 
    static void solve(double **triSup, vector<double> &vars, double *b, const int NUM);

private:
    static void pivotParcial(double **a,double *b, int k, const int NUM);
    static void triangularSuperior(double **a, double *b, const int NUM);
    static void subsRegressiva(double **triSup, vector<double> &vars, double *b, const int NUM);
    
};