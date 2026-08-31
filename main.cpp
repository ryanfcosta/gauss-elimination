#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <iomanip>

#define NUM 4
using namespace std;


void exibeMatriz(double A[NUM][NUM] ,double B[NUM]){
    for(int i = 0; i < NUM ; i++){
        for(int j = 0; j < NUM; j++){
            cout << A[i][j] << " ";
        }
        cout <<" | " << B[i] <<"\n";
    }

}


void pivotParcial(double A[NUM][NUM],double B[NUM], int k){
    double maior;
    int maiorLine = 0;

    if(A[k][k] < 0){
        maior = A[k][k] * -1.0;
    } else{
        maior = A[k][k];
    }


    for(int i = k+1; i<NUM ;i++){
        double temp = A[i][k];
        if(A[i][k] < 0){
            temp = A[i][k] * -1;
        }
        if(temp > maior){
            maior = temp;
            maiorLine = i;
        }
    }

    if(maiorLine){
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

void triangularSuperior(double A[NUM][NUM], double B[NUM]){
    for(int k = 0; k < NUM - 1; k++){
        pivotParcial(A,B, k);
        for(int i = k + 1; i < NUM; i++){
            if(A[i][k]){
                double m = A[i][k] / A[k][k];

                for(int j = 0; j < NUM; j++)
                    A[i][j] = A[i][j] - m * A[k][j];
                
                B[i] = B[i] - m * B[k];
            }
        }
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

int main(void){
    cout << fixed << setprecision(4);
    //criaMatriz(A, B);
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

    double A[NUM][NUM] = {
        {3,-4,-6,1},
        {-2, 3, 14, -1},
        {1,3,2,-5},
        {-10,-1,-1,0}
    };
    double B[NUM] {
        -5, 7 ,0 ,10
    };

    triangularSuperior(A,B);
    exibeMatriz(A,B);
    vector <double> vars;
    subsRegressiva(A, vars, B);

    return 0;
}