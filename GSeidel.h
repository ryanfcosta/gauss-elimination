#pragma once

#include "GJacobi.h"

class GSeidel : public GJacobi{

public:
    static void solve(double* *A, vector<double> &vars, double* B, const int NUM);

private:
    static bool critSassenfeld(double **A, const int NUM);
    static void gaussSeidel(double** A, vector<double> &vars, double* B, const int NUM);
};
