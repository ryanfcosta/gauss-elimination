#include "Elimination.h"
#include "GJacobi.h"
#include "GSeidel.h"

#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
#include <vector>

#include <QApplication>

#define NUM 4

using namespace std;

void exibeMatriz(double **A ,double *B){
    for(int i = 0; i < NUM ; i++){
        for(int j = 0; j < NUM; j++){
            cout << A[i][j] << " ";
        }
        cout <<" | " << B[i] <<"\n";
    }
        cout << endl;
}

int main(int argc, char* argv[]){
    cout << fixed << setprecision(9);

    double tempA[NUM][NUM] = {
        {-18,3,4,-5},
        {1, -6, 0, 3},
        {1,4,-8,-1},
        {-2,3,-4,-10}
    };

    double tempB[NUM] {
        0, 10 ,5 ,-3
    };

    double **A = new double*[NUM];
    double B[NUM];
    for (int i = 0; i < NUM; i++) {
        B[i] = tempB[i];
        A[i] = new double[NUM];
        for (int j = 0; j < NUM; j++) {
            A[i][j] = tempA[i][j];
        }
    }
    vector <double> vars(NUM, 0.0);
    Elimination::solve(A,vars,B,NUM);
    exibeMatriz(A,B);

    for(auto const x : vars){
        cout << x << " ";
    } cout << endl;
    for (int i = 0; i < NUM; i++) delete[] A[i];
    delete[] A;


    double ** nA = new double*[NUM];
    for (int i = 0; i < NUM; i++) {
        B[i] = tempB[i];
        nA[i] = new double[NUM];
        for (int j = 0; j < NUM; j++) {
            nA[i][j] = tempA[i][j];
        }
    }
    
    vars.assign(NUM, 0.0);
    GJacobi::solve(nA,vars,B,NUM);

    for(auto const x : vars){
        cout << x << " ";
    }cout << endl;

    vars.assign(NUM, 0.0);
    GSeidel::solve(nA,vars,B,NUM);

    for(auto const x : vars){
        cout << x << " ";
    }cout << endl;
    
    for (int i = 0; i < NUM; i++) delete[] nA[i];
    delete[] nA;

    return 0;
}
