#include "GSeidel.h"

bool GSeidel::critSassenfeld(double **A, const int NUM){
    vector <double> beta(NUM, 0.0); 
    double maxBeta = 0.0;

    for(int i = 0; i< NUM; i++){
        double sum = 0.0;
        for(int j = 0; j < NUM; j++){
            if(i != j){
                if(j < i){
                    sum += fabs(A[i][j]) * beta[j]; 
                }
                else{
                    sum += fabs(A[i][j]);                    
                }
            }
        }
        beta[i] = sum / fabs(A[i][i]);
        if(beta[i] > maxBeta){
            maxBeta = beta[i];
        }
    }
    if(maxBeta >= 1) return false;
    return true;
}

void GSeidel::gaussSeidel(double** A, vector <double> &vars, double* B, const int NUM){
    bool stop = false;
    int reps = 0;

    do{
        vector<double> last(NUM, 0.0);
        for(int k = 0; k < NUM; k++){
            last[k] = vars[k];
        }

        for(int i = 0; i < NUM; i++){
            double sum = 0.0;
            for(int j = 0; j < NUM; j++){
                if(i!=j){
                    sum += A[i][j] * vars[j];
                }
            }
            vars[i] = (B[i] - sum) / A[i][i];
        }
        stop = GJacobi::critParada(last,vars,NUM, 1e-9);
        reps++;
    }while(!stop && reps < 1000);
}

void GSeidel::solve(double* *A, vector<double> &vars, double* B, const int NUM){
    if(GJacobi::critLinhas(A, NUM) || GSeidel::critSassenfeld(A, NUM)){
        gaussSeidel(A,vars,B, NUM);
    }else{
        cout << "Não irá convergir" << endl;
    }
}