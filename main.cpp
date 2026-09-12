#include "Elimination.h"
#include "GJacobi.h"
#include "GSeidel.h"

#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
#include <vector>

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QString>

#define NUM 4

using namespace std;

void exibeMatriz(double **a ,double *b){
    for(int i = 0; i < NUM ; i++){
        for(int j = 0; j < NUM; j++){
            cout << a[i][j] << " ";
        }
        cout <<" | " << b[i] <<"\n";
    }
        cout << endl;
}

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QWidget janela;
    janela.setWindowTitle("Gauss Methods Visualization");
    janela.resize(1920,1080);

    QVBoxLayout *main_layout = new QVBoxLayout(&janela);

    QHBoxLayout *visualize_layout = new QHBoxLayout();
    QGridLayout *matrix_layout = new QGridLayout();
    matrix_layout->setSpacing(5);
    QVBoxLayout *results_container = new QVBoxLayout();

    QHBoxLayout *buttons_layout = new QHBoxLayout();
    QVBoxLayout *methods_container = new QVBoxLayout();
    QVBoxLayout *control_container = new QVBoxLayout();

    main_layout->addLayout(visualize_layout);
    main_layout->addLayout(buttons_layout);

    visualize_layout->addLayout(matrix_layout);
    visualize_layout->addLayout(results_container);

    buttons_layout->addLayout(methods_container);
    buttons_layout->addLayout(control_container);

    QLabel* nums_matrix[NUM][NUM + 1];


    cout << fixed << setprecision(9);

    double a_temp[NUM][NUM] = {
        {-18,3,4,-5},
        {1, -6, 0, 3},
        {1,4,-8,-1},
        {-2,3,-4,-10}
    };

    double b_temp[NUM] {
        0, 10 ,5 ,-3
    };

    double **a = new double*[NUM];
    double b[NUM];
    for (int i = 0; i < NUM; i++) {
        b[i] = b_temp[i];
        nums_matrix[i][NUM]->QLabel::setNum(b[i]);
        a[i] = new double[NUM];
        for (int j = 0; j < NUM; j++) {
            a[i][j] = a_temp[i][j];
            nums_matrix[i][j]->QLabel::setNum(a[i][j]);
        }
    }
    vector <double> vars(NUM, 0.0);
    Elimination::solve(a,vars,b,NUM);
    exibeMatriz(a,b);

    for(auto const x : vars){
        cout << x << " ";
    } cout << endl;
    for (int i = 0; i < NUM; i++) delete[] a[i];
    delete[] a;


    double ** a_new = new double*[NUM];
    for (int i = 0; i < NUM; i++) {
        b[i] = b_temp[i];
        a_new[i] = new double[NUM];
        for (int j = 0; j < NUM; j++) {
            a_new[i][j] = a_temp[i][j];
        }
    }
    
    vars.assign(NUM, 0.0);
    GJacobi::solve(a_new,vars,b,NUM);

    for(auto const x : vars){
        cout << x << " ";
    }cout << endl;

    vars.assign(NUM, 0.0);
    GSeidel::solve(a_new,vars,b,NUM);

    for(auto const x : vars){
        cout << x << " ";
    }cout << endl;

    for (int i = 0; i < NUM; i++) delete[] a_new[i];
    delete[] a_new;

    janela.show();
    return app.exec();
}
