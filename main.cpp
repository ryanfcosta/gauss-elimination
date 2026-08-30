#include <iostream>
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
    double A[NUM][NUM] = {
        {3,2,-5,1},
        {1, 4, 1, 0},
        {-2,8,3,-4},
        {-1,0,2,4}
    };
    double B[NUM] {
        8, 2 ,0 ,10
    };


    for(int k = 0; k < NUM -1; k++){
        for(int i = k + 1; i < NUM; i++){
            if(A[i][k] != 0){
                double m = A[i][k] / A[k][k];
                for(int j = 0; j < NUM; j++){
                    A[i][j] = A[i][j] - m * A[k][j];
                }
                
                B[i] = B[i] - m * B[k];
            }
        }
    }
    exibeMatriz(A,B);

    return 0;
}