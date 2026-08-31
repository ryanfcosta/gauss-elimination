#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
#include <vector>
#include <Elimination.h>

#define NUM 4
using namespace std;


void exibeMatriz(double **A ,double *B){
    for(int i = 0; i < NUM ; i++){
        for(int j = 0; j < NUM; j++){
            cout << A[i][j] << " ";
        }
        cout <<" | " << B[i] <<"\n";
    }

}

void subsRegressiva(double triSup[NUM][NUM], vector <double> vars, double B[NUM]){
    for(int i = 0 ;i < NUM; i++){
        double  sum = 0, result;
        for(int k =0; k < i; k++){
            sum += triSup[NUM -i -1][NUM -k -1] * vars[k];
        }
        result = (B[NUM-i - 1] - sum) / triSup[NUM-i -1][NUM-i - 1];
        cout << "x" << NUM-i << "= " << result << endl;
        vars.push_back(result);
    }
}


int main(void){
    cout << fixed << setprecision(4);
    //criaMatriz(A, B);


    double tempA[NUM][NUM] = {
        {3,-4,-6,1},
        {-2, 3, 14, -1},
        {1,3,2,-5},
        {-10,-1,-1,0}
    };
    double B[NUM] {
        -5, 7 ,0 ,10
    };

    double **A = new double*[NUM];
    for (int i = 0; i < NUM; i++) {
        A[i] = new double[NUM];
        for (int j = 0; j < NUM; j++) {
            A[i][j] = tempA[i][j];
        }
    }
    vector <double> vars;

    Elimination::solve(A,vars,B, NUM);
    exibeMatriz(A,B);
    
    return 0;
}


//// TESTES
/*void criaMatriz(double A[NUM][NUM] ,double B[NUM]){
    for(int i = 0; i < NUM ; i++){
        for(int j = 0; j < NUM; j++){
            cout << "Digiite o número do elemento [" << i+1 << "]["<< j+1 << "]" << endl;
            cin  >> A[i][j];
        }
        cout << "Digite o resultado da linha " << i << endl;
        cin  >> B[i];   
    }
}   
*/ 

/*
double A[NUM][NUM] = {
     {3,2,-5,1},
     {1, 4, 1, 0},
     {-2,8,3,-4},
     {-1,0,2,4}
 };
 double B[NUM] {
     8, 2 ,0 ,10
 };
 */