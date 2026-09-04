#include "Elimination.h"

void Elimination::subsRegressiva(double **triSup, vector<double> &vars, double *B, const int NUM){
    for(int i = 0 ;i < NUM; i++){
        double  sum = 0, result;
        for(int k =0; k < i; k++){
            sum += triSup[NUM -i -1][NUM -k -1] * vars[k];
        }
        result = (B[NUM-i - 1] - sum) / triSup[NUM-i -1][NUM-i - 1];
        cout << "x" << NUM-i << "= " << result << endl;
        vars[i] = result;
    }
}


void Elimination::pivotParcial(double **A,double *B, const int k, const int NUM){
    double maior  = fabs(A[k][k]);
    int maiorLine = k;

    for(int i = k+1; i<NUM; i++){
        double temp = fabs(A[i][k]);

        if(temp > maior){
            maior = temp;
            maiorLine = i;
        }
    }

    if(maiorLine != k){
        for(int j = 0; j < NUM; j++){
            double tempA = A[maiorLine][j];
            A[maiorLine][j] = A[k][j];
            A[k][j] = tempA;
        }
        double tempB = B[maiorLine];
        B[maiorLine] = B[k];
        B[k] = tempB;
    }
}

void Elimination::triangularSuperior(double **A, double *B, const int NUM){
    for(int k = 0; k < NUM - 1; k++){
        pivotParcial(A, B, k, NUM);
        for(int i = k + 1; i < NUM; i++){
            if(fabs(A[i][k]) > 1e-12){
                double m = A[i][k] / A[k][k];

                for(int j = 0; j < NUM; j++)
                    A[i][j] = A[i][j] - m * A[k][j];
                
                B[i] = B[i] - m * B[k];
            }
        }
    }
}

void Elimination::solve(double **A, vector<double> &vars, double *B, const int NUM = 4){
    triangularSuperior(A, B, NUM);
    subsRegressiva(A, vars, B, NUM);
}  