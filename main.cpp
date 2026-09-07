    #include "Elimination.h"
    #include "GJacobi.h"
    #include "GSeidel.h"

    #include <iostream>
    #include <string>
    #include <sstream> 
    #include <iomanip>
    #include <vector>

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

    int main(void){
        cout << fixed << setprecision(9);
        //criaMatriz(A, B);


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
        exibeMatriz(nA,B);

        for(auto const x : vars){
            cout << x << " ";
        }cout << endl;

        for (int i = 0; i < NUM; i++) delete[] nA[i];
        delete[] nA;

        vars.assign(NUM, 0.0);
        double ** n2A = new double*[NUM];
        for (int i = 0; i < NUM; i++) {
            B[i] = tempB[i];
            n2A[i] = new double[NUM];
            for (int j = 0; j < NUM; j++) {
                n2A[i][j] = tempA[i][j];
            }
        }
        
        GSeidel::solve(n2A,vars,B,NUM);
        exibeMatriz(n2A,B);

        for(auto const x : vars){
            cout << x << " ";
        }cout << endl;

        for (int i = 0; i < NUM; i++) delete[] n2A[i];
        delete[] n2A;

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