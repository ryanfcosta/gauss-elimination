#include <cmath>
#include <iostream>
#include <vector>
using namespace std; 

class GJacobi{
public:
    bool critLinhas(const double** A, const int NUM){
        for(int i = 0; i < NUM; i++){
            double sum = 0, alpha = 0;
            for(int j = 0; j < NUM; j++){
                if(i != j){
                    sum += fabs(A[i][j]);
                }
            }
            alpha = sum/fabs(A[i][i]);
            cout << "alpha "<< i << " " << alpha;

            if(alpha >= 1) return false;
        }
        return true;
    }

    void gaussJacobi(const double** A, vector <double> &vars, const double* B, const int NUM){
        for(int k = 0; k < NUM; k++) vars.push_back(0);
        double temp[NUM];

        for(int i = 0; i < NUM; i++){
            double sum = 0;
            for(int j = 0 ; j < NUM; j++){
                if( i!= j){
                    sum += A[i][j] * vars[j];
                }
                temp[i] = (B[i] - sum) / A[i][i];
            } 
        }
        
    }
};